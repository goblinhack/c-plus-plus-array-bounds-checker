#define DEBUG
#define ENABLE_ASSERT
#define ENABLE_ABORT
#include "array_bounds_check.h"

void array_bounds_check (void) {
    const auto xdim = 3;
    const auto ydim = 2;
    const auto zdim = 1;

    std::cout << std::endl;
    std::cout << "One dimensional array test, should pass" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::array<int, xdim> a;
    for (auto i = 0; i < xdim; i++) {
        set(a, i, i);
        ASSERT(get(a, i) == i);
    }

    std::cout << std::endl;
    std::cout << "Two dimensional array test, should pass" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::array<std::array<int, ydim>, xdim> b;
    for (auto x = 0; x < xdim; x++) {
        for (auto y = 0; y < ydim; y++) {
            set(b, x, y, x+y);
            ASSERT(get(b, x, y) == x+y);
        }
    }

    std::cout << std::endl;
    std::cout << "Three dimensional array test, should pass" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::array<std::array<std::array<int, zdim>, ydim>, xdim> c;
    for (auto x = 0; x < xdim; x++) {
        for (auto y = 0; y < ydim; y++) {
            for (auto z = 0; z < zdim; z++) {
                set(c, x, y, z, x+y);
                ASSERT(get(c, x, y, z) == x+y+z);
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Valid sets, array should pass" << std::endl;
    std::cout << "=============================" << std::endl;
    set(c, xdim-1, ydim-1, zdim-1, 42);
    set(c, 0, 0, 0, 42);

    std::cout << std::endl;
    std::cout << "Invalid gets, array should fail" << std::endl;
    std::cout << "===============================" << std::endl;
    // crash likely if ENABLE_ABORT is not enabled
    get(c, xdim, ydim-1, zdim-1);
}

int main (void) {

    extern void array_bounds_check(void);
    array_bounds_check();
}
