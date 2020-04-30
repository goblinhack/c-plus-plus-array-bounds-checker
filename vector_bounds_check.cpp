#define DEBUG
#define ENABLE_ASSERT
#define ENABLE_ABORT
#include "vector_bounds_check.h"

void vector_bounds_check (void) {
    const auto xdim = 3;
    const auto ydim = 2;
    const auto zdim = 1;

    std::cout << std::endl;
    std::cout << "One dimensional vector test, should pass" << std::endl;
    std::cout << "========================================" << std::endl;
    std::vector<int> a;
    a.resize(xdim);
    for (auto i = 0; i < xdim; i++) {
        set(a, i, i);
        ASSERT(get(a, i) == i);
    }

    std::cout << std::endl;
    std::cout << "Two dimensional vector test, should pass" << std::endl;
    std::cout << "========================================" << std::endl;
    std::vector<std::vector<int> > b;
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

    std::cout << std::endl;
    std::cout << "Three dimensional vector test, should pass" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::vector<std::vector<std::vector<int> > > c;
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

    std::cout << std::endl;
    std::cout << "Valid sets, vector should pass" << std::endl;
    std::cout << "==============================" << std::endl;
    set(c, xdim-1, ydim-1, zdim-1, 42);
    set(c, 0, 0, 0, 42);

    std::cout << std::endl;
    std::cout << "Invalid gets, vector should fail" << std::endl;
    std::cout << "================================" << std::endl;
    // crash likely if ENABLE_ABORT is not enabled
    get(c, xdim, ydim-1, zdim-1);
    get(c, xdim-1, ydim, zdim-1);
    get(c, xdim-1, ydim-1, zdim);
}

int main (void) {

    extern void vector_bounds_check(void);
    vector_bounds_check();
}
