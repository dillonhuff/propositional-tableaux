# indicate where the object files are to be created
CC         := g++
LINKER     := $(CC)
CFLAGS	   := -g -Wall

HEADERS :=  $(shell find -type f -name '*.h')
SOURCES :=  $(shell find -type f -name '*.cpp')
OBJS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: tests.x

tests.x:	$(OBJS) $(HEADERS)
		$(LINKER) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o
	rm -f tests.x
