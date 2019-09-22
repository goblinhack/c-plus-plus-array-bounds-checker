#include <vector>
#include "bounds_check.h"

//
// Single dimension vector check
//
template<class TYPE>
void set(std::vector<TYPE>& vec, std::size_t X, TYPE v){
    DODEBUG(std::cerr << "set [" << X << "] = " << v << std::endl);
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    vec[X] = v;
}    

template<class TYPE>
TYPE& get(std::vector<TYPE> & vec, std::size_t X){
    DODEBUG(std::cerr << "get [" << X << "] = ");
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    DODEBUG(std::cerr << vec[X] << std::endl);
    return (vec[X]);
}    

//
// Two dimension vector check
//
template<class TYPE>
void set(std::vector<std::vector<TYPE>>& vec, 
         std::size_t X, std::size_t Y, TYPE v){
    DODEBUG(std::cerr << 
            "set [" << X << "][" << Y << "] = " << v << std::endl);
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    ASSERT(Y >= 0)
    ASSERT(Y < vec[X].size())
    vec[X][Y] = v;
}    

template<class TYPE>
TYPE& get(std::vector<std::vector<TYPE>> & vec, 
          std::size_t X, std::size_t Y){
    DODEBUG(std::cerr << "get [" << X << "][" << Y << "] = ");
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    ASSERT(Y >= 0)
    ASSERT(Y < vec[X].size())
    DODEBUG(std::cerr << vec[X][Y] << std::endl);
    return (vec[X][Y]);
}    

//
// Three dimension vector check
//
template<class TYPE>
void set(std::vector<std::vector<std::vector<TYPE>>>& vec, 
         std::size_t X, std::size_t Y, std::size_t Z, TYPE v){
    DODEBUG(std::cerr << 
            "set [" << X << "][" << Y << "][" << Z << "] = " << v << std::endl);
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    ASSERT(Y >= 0)
    ASSERT(Y < vec[X].size())
    ASSERT(Z >= 0)
    ASSERT(Z < vec[X][Y].size())
    vec[X][Y][Z] = v;
}    

template<class TYPE>
TYPE& get(std::vector<std::vector<std::vector<TYPE>>> & vec, 
          std::size_t X, std::size_t Y, std::size_t Z){
    DODEBUG(std::cerr << "get [" << X << "][" << Y << "][" << Z << "] = ");
    ASSERT(X >= 0)
    ASSERT(X < vec.size())
    ASSERT(Y >= 0)
    ASSERT(Y < vec[X].size())
    ASSERT(Z >= 0)
    ASSERT(Z < vec[X][Y].size())
    DODEBUG(std::cerr << vec[X][Y][Z] << std::endl);
    return (vec[X][Y][Z]);
}    
