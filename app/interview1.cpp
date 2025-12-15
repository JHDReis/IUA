
// implement C++ remove_if, that given an array and a filter criteria that moves
// matching elements to the end of the array

#include <Vector.h>
#include <iostream>
#include "StopWatch.h"
#include <random>
#include <ranges>


auto dice()
{
    static std::uniform_int_distribution<int> distr{1, 10};
    static std::random_device device;
    static std::mt19937 engine {device()};
    return distr(engine);
}


int main()
{
    StopWatch t1("fill");
    Vector<int> v(1000000);
    t1.~StopWatch();

    {
        StopWatch test("random fill");
        std::ranges::generate(v[0], v[v.getSize() - 1], dice);
    }

    {
        auto filter = [](int item) { return item % 2 == 0; };
        StopWatch test("remove_if");
        v.remove_if(filter);
    }

    return 0;
}