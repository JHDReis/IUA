
#ifndef ALGORITHMS_ARITHMETICTYPE_H
#define ALGORITHMS_ARITHMETICTYPE_H

template<typename T> struct ArithmeticType {
    friend T operator+(const T& lhs, const T& rhs)
    {
        T result(lhs);
        return result += rhs;
    }
    friend T operator-(const T& lhs, const T& rhs)
    {
        T result(lhs);
        return result -= rhs;
    }
    friend T operator*(const T& lhs, const T& rhs)
    {
        T result(lhs);
        return result *= rhs;
    }
    friend T operator/(const T& lhs, const T& rhs)
    {
        T result(lhs);
        return result /= rhs;
    }
    friend T operator%(const T& lhs, const T& rhs)
    {
        T result(lhs);
        return result %= rhs;
    }
    friend T operator<<(const T& lhs, const T& shift)
    {
        T result(lhs);
        return result <<= shift;
    }
    friend T operator>>(const T& lhs, const T& shift)
    {
        T result(lhs);
        return result >> shift;
    }
};

#endif // ALGORITHMS_ARITHMETICTYPE_H
