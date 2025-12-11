#include "catch2/catch_all.hpp"

#include "Vector.h"

TEST_CASE("tests operator", "[Vector]")
{

    SECTION("test operator *")
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

    SECTION("test operator -")
    {
        Vector<int> v;
        v.append(1);
        v.append(2);
        v.append(3);
        v.append(4);
        v.append(5);

        auto b = -v;

        CHECK(*b[0] == -1);
        CHECK(*b[1] == -2);
        CHECK(*b[2] == -3);
        CHECK(*b[3] == -4);
        CHECK(*b[4] == -5);
    }

}