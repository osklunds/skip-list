
#include "list.h"
#include "catch.hpp"

TEST_CASE("contains and example_list", "[contains]") {
    List list = List::example_list();

    REQUIRE(list.contains(0) == false);
    REQUIRE(list.contains(1) == false);
    REQUIRE(list.contains(48) == false);
    REQUIRE(list.contains(12) == true);
    REQUIRE(list.contains(18) == true);
    REQUIRE(list.contains(19) == true);
    REQUIRE(list.contains(34) == true);
    REQUIRE(list.contains(47) == true);
}

TEST_CASE("insert and example_list", "[insert]") {
    List list = List::example_list();
    list.insert(7);
    list.insert(48);
    list.insert(34);
    list.insert(20);

    REQUIRE(list.contains(0) == false);
    REQUIRE(list.contains(7) == true);
    REQUIRE(list.contains(12) == true);
    REQUIRE(list.contains(18) == true);
    REQUIRE(list.contains(19) == true);
    REQUIRE(list.contains(20) == true);
    REQUIRE(list.contains(34) == true);
    REQUIRE(list.contains(47) == true);
    REQUIRE(list.contains(48) == true);
}

TEST_CASE("insert and empty list", "[insert]") {
    List list;
    list.insert(7);
    list.insert(48);
    list.insert(34);
    list.insert(20);

    REQUIRE(list.contains(0) == false);
    REQUIRE(list.contains(7) == true);
    REQUIRE(list.contains(20) == true);
    REQUIRE(list.contains(34) == true);
    REQUIRE(list.contains(48) == true);
}