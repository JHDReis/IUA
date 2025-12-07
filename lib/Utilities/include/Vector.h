#pragma once

#include "Utility.h"
#include "ArithmeticType.h"

#include <algorithm>
#include <cassert>


template<typename ITEM> class Vector : public ArithmeticType<Vector<ITEM>> {

    enum { MIN_CAPACITY = 8 };
    int capacity = MIN_CAPACITY, size = 0;
    ITEM* array{nullptr};

public:
    explicit Vector(): array(rawMemory<ITEM>(capacity)) {}

    explicit Vector(int initialCapacity, const ITEM& value = ITEM()):
        capacity(std::ranges::max(initialCapacity, MIN_CAPACITY)),
        array(rawMemory<ITEM>(capacity)) {}

    ITEM* getArray() { return array; }
    const ITEM* getArray() const { return array; }
    int getSize() const { return size; }

    ITEM* operator[](int index)
    {
        assert(index >= 0 && index < size && "Index out of bounds");
        return array + index;
    }

    const ITEM* operator[](int index) const
    {
        assert(index >= 0 && index < size && "Index out of bounds");
        return array + index;
    }
};
