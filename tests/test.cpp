#include "Utility.h"
#include <catch2/catch_all.hpp>
#include <iostream>

TEST_CASE("Basic test", "[main]")
{
    REQUIRE(getVersion() == "0.1");
}

class User {
public:
    int id;
    std::string name;

    User(int id, const std::string& name): id(id), name(name)
    {
        std::cout << "Constructing User: " << name << "\n";
    }

    ~User() { std::cout << "Destroying User: " << name << "\n"; }

    User& operator=(const User& rhs) { return genericAssign(*this, rhs); }
};

TEST_CASE("Generic Assign", "[main]")
{

    User a(1, "A");
    User b(2, "B");

    a = b;

    CHECK(b.id == a.id);
}
