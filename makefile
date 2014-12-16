CC	:= g++
LINKER	:= $(CC)
CFLAGS	:= -g -O3 -std=c++11 -Wall

HEADERS	:= $(shell find ./ -type f -name '*.h')
SOURCES	:= $(shell find ./ -type f -name '*.cpp')
OBJECTS	:= $(patsubst %.cpp, %.o, $(SOURCES))

# Compile cpp sourece files to object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

tests.x: $(OBJECTS) $(HEADERS)
	$(LINKER) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f *.o
	rm -f *.x
