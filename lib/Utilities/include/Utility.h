#pragma once

#include "Comparators.h"
#include "ArrayComparator.h"
#include "LexicographicComparator.h"
#include <map>
#include <new>
#include <optional>
#include <string>


std::string getVersion();

template <typename ITEM> ITEM *rawMemory(const int n)
{
    return static_cast<ITEM *>(::operator new(sizeof(ITEM) * n));
}

inline void rawDelete(void *array)
{
    ::operator delete(array);
}

template <typename ITEM> void rawDestructor(ITEM *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i].~ITEM();
    }
    rawDelete(array);
}

//  Placement New.
// In C++, this specific syntax is used to construct an object at a specific
// memory address that has already been allocated,// rather than allocating
// fresh memory from the heap.
template <typename TYPE> TYPE &genericAssign(TYPE &to, TYPE const &rhs)
{
    if (&to != &rhs)
    {
        to.~TYPE();
        new (&to) TYPE(rhs);
    }
    return to;
}

template <typename KEY, typename VALUE> struct KVPair
{
    KEY key;
    VALUE value;

    explicit KVPair(const KEY &k = KEY(), const VALUE &v = VALUE()) : key(k), value(v)
    {
    }
};

struct EMPTY
{
};

// Provide the appropriate comparators to be used by generic functions so that
// they can use STL
template <typename ITEM> bool operator==(const ITEM &lhs, const ITEM &rhs)
{
    return lhs <= rhs && rhs <= lhs;
}

template <typename ITEM> bool operator!=(const ITEM &lhs, const ITEM &rhs)
{
    return lhs == rhs ? false : true;
}

template <typename ITEM> struct PointerTransform
{
    const ITEM &operator()(const ITEM *item) const
    {
        assert(item);
        return *item;
    }
};

template <typename ITEM, typename COMPARATOR = DefaultComparator<ITEM>>
using PointerComparator = TransformComparator<ITEM *, PointerTransform<ITEM>, COMPARATOR>;

template <typename ITEM> struct IndexTransform
{
    const ITEM *array;

    explicit IndexTransform(const ITEM *array) : array(array)
    {
    }

    const ITEM &operator()(int index) const
    {
        return array[index];
    }
};

template <typename ITEM, typename COMPARATOR = DefaultComparator<ITEM>>
using IndexComparator = TransformComparator<int, IndexTransform<ITEM>, COMPARATOR>;

template <typename FIRST, typename SECOND> struct PairFirstTransform
{
    const FIRST &operator()(const std::pair<FIRST, SECOND> &pair) const
    {
        return pair.first;
    }
};

template <typename FIRST, typename SECOND, typename COMPARATOR = DefaultComparator<FIRST>>
using PairFirstComparator = TransformComparator<std::pair<FIRST, SECOND>, PairFirstTransform<FIRST, SECOND>, COMPARATOR>;


