Simple C++ 11 std::array and std::vector bounds checking
========================================================

Sometimes I want to be able to add array bounds checking in my code and often
things like valgrind are too heavy for the task. This little hack adds set()
and get() accessors for std::array. e.g.:

<pre>
    std::array<std::array<std::array<int, zdim>, ydim>, xdim> c;
    set(c, 0, 0, 0, 42);
    (void) get(c, 0, 0, 0);
</pre>

If you want to include a trace of set() and get() calls, enable:
<pre>
#define DEBUG
</pre>

To print an assertion on out of bounds (and continue):
<pre>
#define ENABLE_ASSERT
</pre>

To call abort() on assertion:
<pre>
#undef ENABLE_ABORT
</pre>

Which should drop you into your debugger. If you do not enable this, then
the code will continue and likely crash anyway.

Header
======

<pre>
#define DEBUG
#define ENABLE_ASSERT
#define ENABLE_ABORT
#include "array_bounds_check.h"
</pre>

std::array example
==================

<pre>
#define ENABLE_ASSERT
#define ENABLE_ABORT
#include "array_bounds_check.h"

int main (void) {
    const auto xdim = 3;
    const auto ydim = 2;
    const auto zdim = 1;

    //
    // One dimensional array
    //
    std::array<int, xdim> a;
    for (auto i = 0; i < xdim; i++) {
        set(a, i, i);
        ASSERT(get(a, i) == i);
    }

    //
    // Two dimensional array
    //
    std::array<std::array<int, ydim>, xdim> b;
    for (auto x = 0; x < xdim; x++) {
        for (auto y = 0; y < ydim; y++) {
            set(b, x, y, x+y);
            ASSERT(get(b, x, y) == x+y);
        }
    }

    //
    // Three dimensional array
    //
    std::array<std::array<std::array<int, zdim>, ydim>, xdim> c;
    for (auto x = 0; x < xdim; x++) {
        for (auto y = 0; y < ydim; y++) {
            for (auto z = 0; z < zdim; z++) {
                set(c, x, y, z, x+y);
                ASSERT(get(c, x, y, z) == x+y+z);
            }
        }
    }
}
</pre>

std::vector example
===================

<pre>
#define ENABLE_ASSERT
#define ENABLE_ABORT
#include "vector_bounds_check.h"

int main (void) {
    const auto xdim = 3;
    const auto ydim = 2;
    const auto zdim = 1;

    //
    // One dimensional vector
    //
    std::vector<int> a;
    a.resize(xdim);
    for (auto i = 0; i < xdim; i++) {
	set(a, i, i);
        ASSERT(get(a, i) == i);
    }

    //
    // Two dimensional vector
    //
    std::vector<std::vector<int>> b;
    b.resize(xdim);
    for (auto x = 0; x < b.size(); x++) {
        b[x].resize(ydim);
    }
    for (auto x = 0; x < xdim; x++) {
	for (auto y = 0; y < ydim; y++) {
	    set(b, x, y, x+y);
	    ASSERT(get(b, x, y) == x+y);
	}
    }

    //
    // Three dimensional vector
    //
    std::vector<std::vector<std::vector<int>>> c;
    c.resize(xdim);
    for (auto x = 0; x < b.size(); x++) {
        c[x].resize(ydim);
        for (auto y = 0; y < b[x].size(); y++) {
            c[x][y].resize(zdim);
        }
    }
    for (auto x = 0; x < xdim; x++) {
	for (auto y = 0; y < ydim; y++) {
	    for (auto z = 0; z < zdim; z++) {
		set(c, x, y, z, x+y);
		ASSERT(get(c, x, y, z) == x+y+z);
	    }
	}
    }
}
</pre>

Sample error
============

<pre>
Assert 'X < arr.size()' failed at line 85, file ./array_bounds_check.h, function set()
</pre>

And in a debugger:
==================

<pre>
lldb array_bounds_check
(lldb) r
Assert 'X < arr.size()' failed at line 85, file ./array_bounds_check.h, function set()
Process 39381 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = signal SIGABRT
    frame #0: 0x00007fff5d422b66 libsystem_kernel.dylib`__pthread_kill + 10
libsystem_kernel.dylib`__pthread_kill:
->  0x7fff5d422b66 <+10>: jae    0x7fff5d422b70            ; <+20>
    0x7fff5d422b68 <+12>: movq   %rax, %rdi
    0x7fff5d422b6b <+15>: jmp    0x7fff5d419ae9            ; cerror_nocancel
    0x7fff5d422b70 <+20>: retq
Target 0: (array_bounds_check) stopped.
(lldb) bt
* thread #1, queue = 'com.apple.main-thread', stop reason = signal SIGABRT
  * frame #0: 0x00007fff5d422b66 libsystem_kernel.dylib`__pthread_kill + 10
    frame #1: 0x00007fff5d5ed080 libsystem_pthread.dylib`pthread_kill + 333
    frame #2: 0x00007fff5d37e1ae libsystem_c.dylib`abort + 127
    frame #3: 0x0000000100002112 array_bounds_check`void set<int, 3ul, 2ul, 1ul>(std::__1::array<std::__1::array<std::__1::array<int, 1ul>, 2ul>, 3ul>&, unsigned long, unsigned long, unsigned long, int) [inlined] std::__1::basic_ostream<char, std::__1::char_traits<char> >& std::__1::endl<char, std::__1::char_traits<char> >(__os=<unavailable>) at ostream:1002
    frame #4: 0x00000001000020f4 array_bounds_check`void set<int, 3ul, 2ul, 1ul>(std::__1::array<std::__1::array<std::__1::array<int, 1ul>, 2ul>, 3ul>&, unsigned long, unsigned long, unsigned long, int) [inlined] std::__1::basic_ostream<char, std::__1::char_traits<char> >::operator<<(this=<unavailable>)(std::__1::basic_ostream<char, std::__1::char_traits<char> >&)) at ostream:195
    frame #5: 0x00000001000020f4 array_bounds_check`void set<int, 3ul, 2ul, 1ul>(arr=0x00007ffeefbfeac8, X=3, Y=1, Z=0, v=42) at array_bounds_check.h:85
    frame #6: 0x0000000100000f50 array_bounds_check`main at array_bounds_check.cpp:43
    frame #7: 0x00007fff5d2d2015 libdyld.dylib`start + 1
</pre>

Building
========

Do

<pre>
    sh ./RUNME
</pre>

Or, if that fails, manual build:

<pre>
    c++ -std=c++11 -Werror -g -ggdb3 -O2 -Wall -Wall -c -o .o/main.o main.cpp
    c++ -std=c++11 -Werror -g -ggdb3 -O2 -Wall -Wall -c -o .o/array_bounds_check.o array_bounds_check.cpp
    c++ -std=c++11 -Werror -g -ggdb3 -O2 -Wall -Wall -c -o .o/vector_bounds_check.o vector_bounds_check.cpp
</pre>

To test:

<pre>
    ./bounds_check
</pre>
