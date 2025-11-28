#pragma once

#include <map>
#include <new>
#include <string>

std::string getVersion();

template<typename ITEM> ITEM* rawMemory(const int n)
{
    return static_cast<ITEM*>(::operator new(sizeof(ITEM) * n));
}

inline void rawDelete(void* array)
{
    ::operator delete(array);
}

template<typename ITEM> void rawDestructor(ITEM* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i].~ITEM();
    }
    rawDelete(array);
}

//  Placement New.
// In C++, this specific syntax is used to construct an object at a specific memory address
// that has already been allocated,// rather than allocating fresh memory from the heap.
template<typename TYPE> TYPE& genericAssign(TYPE& to, TYPE const& rhs)
{
    if (&to != &rhs) {
        to.~TYPE();
        new (&to) TYPE(rhs);
    }
    return to;
}

template<typename KEY, typename VALUE> struct KVPair {
    KEY key;
    VALUE value;
    explicit KVPair(const KEY& k = KEY(), const VALUE& v = VALUE())
        : key(k), value(v)
    {}
};