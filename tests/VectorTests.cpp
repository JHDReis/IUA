#include "catch2/catch_all.hpp"

#include "Vector.h"

TEST_CASE("tests operator", "[Vector]")
{
    Vector<int> v;

    v.append(1);
    v.append(2);
    v.append(3);

    Vector<int> b = v * 3;

    CHECK(*b[0] == 3);
    CHECK(*b[1] == 6);
    CHECK(*b[2] == 9);

}