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
NAME=bounds_check
OBJDIR=.o

TARGET_OBJECTS=$(OBJDIR)/main.o $(OBJDIR)/array_bounds_check.o $(OBJDIR)/vector_bounds_check.o

EXTRA_CFLAGS=-std=c++11

$(OBJDIR)/%.o: %.cpp
	@echo $(CXX) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<
	@$(CXX) $(EXTRA_CFLAGS) $(CFLAGS) -c -o $@ $<

#
# link
#
TARGET=$(NAME)$(EXE)
$(TARGET): $(TARGET_OBJECTS)
	$(CXX) $(TARGET_OBJECTS) $(LDLIBS) -o $(TARGET)

#
# To force clean and avoid "up to date" warning.
#
.PHONY: clean
.PHONY: clobber

clean:
	rm -rf $(TARGET) $(OBJDIR)/*.o

clobber: clean
	mkdir -p $(OBJDIR)

all: $(TARGET) 
# DO NOT DELETE

.o/array_bounds_check.o: array_bounds_check.h bounds_check.h
.o/array_bounds_check.o: /usr/include/assert.h /usr/include/sys/cdefs.h
.o/array_bounds_check.o: /usr/include/sys/_symbol_aliasing.h
.o/array_bounds_check.o: /usr/include/sys/_posix_availability.h
.o/vector_bounds_check.o: vector_bounds_check.h bounds_check.h
.o/vector_bounds_check.o: /usr/include/assert.h /usr/include/sys/cdefs.h
.o/vector_bounds_check.o: /usr/include/sys/_symbol_aliasing.h
.o/vector_bounds_check.o: /usr/include/sys/_posix_availability.h
