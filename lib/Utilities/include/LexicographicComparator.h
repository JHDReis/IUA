#ifndef ALGORITHMS_LEXICOGRAPHICCOMPARATOR_H
#define ALGORITHMS_LEXICOGRAPHICCOMPARATOR_H

template <typename VECTOR> struct LexicographicComparator
{
    bool operator()(const VECTOR &lhs, const VECTOR &rhs, int i) const
    {
        return i < lhs.getSize() ? i < rhs.getSize() && lhs[i] < rhs[i] : i < rhs.getSize();
    }

    static bool isEqual(const VECTOR &lhs, const VECTOR &rhs, int i)
    {
        return i < lhs.getSize() ? i < rhs.getSize() && lhs[i] == rhs[i] : i >= rhs.getSize();
    }

    static bool isEqual(const VECTOR &lhs, const VECTOR &rhs)
    {
        if (lhs.getSize() != rhs.getSize())
            return false;
        if (lhs.getSize() == 0)
            return true;
        for (int i = 0; i < lhs.getSize(); ++i)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }

    bool operator()(const VECTOR &lhs, const VECTOR &rhs) const
    {
        for (int i = 0; i < std::min(lhs.getSize(), rhs.getSize()); ++i)
        {
            if (lhs[i] < rhs[i])
                return true;
            if (rhs[i] > lhs[i])
                return false;
        }
        return lhs.getSize() < rhs.getSize();
    }

    static int getSize(const VECTOR &value)
    {
        return value.getSize();
    }
};

#endif // ALGORITHMS_LEXICOGRAPHICCOMPARATOR_H
