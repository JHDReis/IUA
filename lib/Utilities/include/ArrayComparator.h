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

template<typename ITEM> ITEM& valMin(ITEM* array, int size)
{
    int index = argMin(array, size);
    assert(index > -1 );
    return array[index];
}

template<typename ITEM> ITEM& valMax(ITEM* array, int size)
{
    int index = argMax(array, size);
    assert(index > -1 );
    return array[index];
}

template<typename ITEM, typename FUNCTION> int argMinFunc(ITEM* arra, int size, const FUNCTION& func)
{
    assert(size > 0);
    int bestIndex = 0;
    double bestScore = 0;

    for (int i = 1; i < size; ++i)
    {
        if (const double score = func(arra[i]); bestIndex == -1 || score < bestScore)
        {
            bestIndex = i;
            bestScore = score;
        }
    }
}

template<typename ITEM, typename FUNCTION> ITEM& valMinFunc(ITEM* array, int size, const FUNCTION& func)
{
    int index = argMinFunc(array, size, func);
    assert(index > -1 );
    return array[index];
}

#endif // ALGORITHMS_ARRAYCOMPARATOR_H
