#ifndef ALGORITHMS_COMPARATORS_H
#define ALGORITHMS_COMPARATORS_H

template <typename ITEM> struct DefaultComparator
{
    bool operator()(const ITEM &lhs, const ITEM &rhs) const
    {
        return lhs < rhs;
    }
    bool isEqual(const ITEM &lhs, const ITEM &rhs)
    {
        return lhs == rhs;
    }
};

template <typename ITEM, typename COMPARATOR = DefaultComparator<ITEM>> struct ReverseComparator
{
    COMPARATOR comparator;

    explicit ReverseComparator(const COMPARATOR &c = COMPARATOR()) : comparator(c)
    {
    }
    bool operator()(const ITEM &lhs, const ITEM &rhs) const
    {
        return comparator(rhs, lhs);
    }

    bool isEqual(const ITEM &lhs, const ITEM &rhs)
    {
        return comparator.isEqual(lhs, rhs);
    }
};

template <typename ITEM, typename TRANSFORM, typename COMPARATOR> struct TransformComparator
{
    TRANSFORM t;
    COMPARATOR c;

    explicit TransformComparator(TRANSFORM transform = TRANSFORM(), COMPARATOR comparator = COMPARATOR())
        : t(transform), c(comparator)
    {
    }

    bool operator()(const ITEM &lhs, const ITEM &rhs) const
    {
        return c(t(lhs), t(rhs));
    }

    bool isEqual(const ITEM &lhs, const ITEM &rhs) const
    {
        return c.isEqual(t(lhs), t(rhs));
    }
};
#endif // ALGORITHMS_COMPARATORS_H
