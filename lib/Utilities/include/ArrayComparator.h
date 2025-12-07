#ifndef ALGORITHMS_ARRAYCOMPARATOR_H
#define ALGORITHMS_ARRAYCOMPARATOR_H

#include "Comparators.h"
#include <cassert>
#include <functional>

template <typename ITEM, typename COMPARATOR> int argMin(const ITEM *array, int size, const COMPARATOR &comparator)
{
    assert(size > 0);
    int best = 0;
    for (int i = 1; i < size; ++i)
    {
        if (comparator(array[i], array[best]))
        {
            best = i;
        }
    }
    return best;
}

template<typename ITEM> int argMin(const ITEM *array, int size)
{
    return argMin(array, size, DefaultComparator<ITEM>());
}

template<typename ITEM> int argMax(const ITEM *array, int size)
{
    return argMin(array, size, ReverseComparator<ITEM>());
}

#endif // ALGORITHMS_ARRAYCOMPARATOR_H
