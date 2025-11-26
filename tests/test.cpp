#include <catch2\catch_all.hpp>
#include "Utility.h"

#include <iostream>


TEST_CASE("Basic test", "[main]")
{
    REQUIRE(getVersion() == "0.1");
}
