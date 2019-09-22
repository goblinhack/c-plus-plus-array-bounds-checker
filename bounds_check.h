#include <assert.h>
#include <iostream>

#ifdef ENABLE_ABORT
#define DOABORT abort();
#else
#define DOABORT
#endif

#ifdef DEBUG
#define DODEBUG(x) x
#else
#define DODEBUG(x) 
#endif

#ifdef ENABLE_ASSERT
#define ASSERT(x) \
    if (! (x)) { \
	std::cerr << "Assert '" << #x << "' failed at line " \
                  << __LINE__ << ", file " << __FILE__ \
                  << ", function " << __FUNCTION__ << "()" << std::endl; \
        DOABORT \
    }
#else
#define ASSERT(x)
#endif
