COMPILER_FLAGS=-Werror -g -ggdb3 -O2  # AUTOGEN
    
CLANG_COMPILER_WARNINGS=-Wall -Wall # AUTOGEN
GCC_COMPILER_WARNINGS=-Wall -Wall # AUTOGEN
GXX_COMPILER_WARNINGS=-Wall -Wall # AUTOGEN
COMPILER_WARNINGS=$(GCC_COMPILER_WARNINGS) # AUTOGEN
COMPILER_WARNINGS=$(GXX_COMPILER_WARNINGS) # AUTOGEN
COMPILER_WARNINGS=$(CLANG_COMPILER_WARNINGS) # AUTOGEN
CC=clang # AUTOGEN
# CC=gcc # AUTOGEN
# CC=cc # AUTOGEN
# CC=g++ # AUTOGEN
    
EXE= # AUTOGEN
LDLIBS= # AUTOGEN
CFLAGS=$(COMPILER_FLAGS) $(COMPILER_WARNINGS) # AUTOGEN
TARGETS=array_bounds_check vector_bounds_check

CXXFLAGS=-std=c++11

.SUFFIXES: .cpp

%.o: %.cpp
	- @echo $(CXX) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<
	- @$(CXX) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<

all: $(TARGETS)

clobber:
	rm -f *.o
	rm -f $(TARGETS)

clean:
	rm -f *.o
# DO NOT DELETE

.o/array_bounds_check.o: array_bounds_check.h bounds_check.h
.o/array_bounds_check.o: /usr/include/assert.h /usr/include/sys/cdefs.h
.o/array_bounds_check.o: /usr/include/sys/_symbol_aliasing.h
.o/array_bounds_check.o: /usr/include/sys/_posix_availability.h
.o/vector_bounds_check.o: vector_bounds_check.h bounds_check.h
.o/vector_bounds_check.o: /usr/include/assert.h /usr/include/sys/cdefs.h
.o/vector_bounds_check.o: /usr/include/sys/_symbol_aliasing.h
.o/vector_bounds_check.o: /usr/include/sys/_posix_availability.h
