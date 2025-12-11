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
        array(rawMemory<ITEM>(capacity))
    {
        for (int i = 0; i < capacity; ++i)
            append(value[i]);
    }

    Vector(const Vector& other)
        : capacity(std::max(other.size, static_cast<int>(MIN_CAPACITY))),
          size(other.size), array(rawMemory<ITEM>(capacity))
    {
        for (int i = 0; i < size; ++i) { new (&array[i]) ITEM(other.array[i]); }
    }

    ~Vector() { rawDelete(array); }

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

    void resize()
    {
        ITEM* oldItems = array;
        capacity = std::max(capacity * 2, static_cast<int>(MIN_CAPACITY));
        array = rawMemory<ITEM>(capacity);
        for (int i = 0; i < size; ++i) { new (&array[i]) ITEM(oldItems[i]); }
        rawDelete(oldItems);
    }

    void append(const ITEM& item)
    {
        if (size >= capacity) resize();
        new (&array[size++]) ITEM(item);
    }

    void removeLast()
    {
        assert(size > 0);
        array[--size].~ITEM();
        if (capacity > MIN_CAPACITY && size * 4 < capacity) { resize(); }
    }

    void swap(Vector& other) noexcept
    {
        std::swap(array, other.array);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

    const ITEM& lastItem() const { return array[size - 1]; }
    ITEM& lastItem() { return array[size - 1]; }

    void reverse(int left, int right)
    {
        while (left < right) { std::swap(array[left++], array[right--]); }
    }

    void appendVector(const Vector& rhs)
    {
        for (const ITEM& item : rhs) append(item);
    }

    Vector& operator+=(const Vector& rhs)
    {
        assert(size == rhs.size);
        for (int i = 0; i < size; ++i) { array[i] += rhs.array[i]; }
        return *this;
    }

    Vector& operator-=(const Vector& rhs) const
    {
        assert(size == rhs.size);
        for (int i = 0; i < size; ++i) { array[i] -= rhs.array[i]; }
        return *this;
    }

    template<typename SCALAR> Vector& operator*=(const SCALAR& rhs)
    {
        for (int i = 0; i < size; ++i) { array[i] *= rhs; }
        return *this;
    }

    friend Vector operator*(const Vector& lhs, const ITEM& scalar)
    {
        Vector result(lhs);
        return result *= scalar;
    }

    Vector operator-() const { return Vector(*this) *= -1; }

    bool operator==(const Vector& rhs) const
    {
        if (size != rhs.size) return false;

        for (int i = 0; i < size; ++i) {
            if (array[i] != rhs.array[i]) return false;
        }
        return true;
    }

    friend bool operator==(const Vector& lhs, const Vector& rhs)
    {
        return lhs.size == rhs.size
               && std::equal(lhs.array, lhs.array + lhs.size, rhs.array);
    }

};
