CC	:= g++
LINKER	:= $(CC)
CFLAGS	:= -g -O3 -std=c++11 -Wall -Isrc/ -Itest

SRC_HEADERS	:= $(shell find src -type f -name '*.h')
SRC_SOURCES	:= $(shell find src -type f -name '*.cpp')
SRC_OBJECTS	:= $(patsubst src/%.cpp, obj/src/%.o, $(SRC_SOURCES))

TEST_HEADERS	:= $(shell find test -type f -name '*.h')
TEST_SOURCES	:= $(shell find test -type f -name '*.cpp')
TEST_OBJECTS	:= $(patsubst test/%.cpp, obj/test/%.o, $(TEST_SOURCES))

obj/src/%.o: src/%.cpp $(SRC_HEADERS)
	@mkdir -p obj/src
	$(CC) $(CFLAGS) -c $< -o $@

obj/test/%.o: test/%.cpp $(SRC_HEADERS) $(SRC_OBJECTS) $(TEST_HEADERS)
	@mkdir -p obj/test
	$(CC) $(CFLAGS) -c $< -o $@

tests: tests.x

tests.x: $(TEST_OBJECTS) $(TEST_HEADERS) $(SRC_OBJECTS) $(SRC_HEADERS)
	$(LINKER) $(CFLAGS) $(TEST_OBJECTS) $(SRC_OBJECTS) -o $@

clean:
	rm -rf obj/
	rm -f tests.x
