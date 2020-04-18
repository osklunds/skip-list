
#include "list.h"
#include "catch.hpp"

TEST_CASE("contains and example_list", "[contains]") {
    Node::initialize_randomness();

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
    Node::initialize_randomness();

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
    Node::initialize_randomness();
    
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

TEST_CASE("remove and example_list", "[remove]") {
    Node::initialize_randomness();

    List list = List::example_list();

    list.remove(18);
    list.remove(34);
    list.remove(35);
    
    REQUIRE(list.contains(12) == true);
    REQUIRE(list.contains(18) == false);
    REQUIRE(list.contains(19) == true);
    REQUIRE(list.contains(34) == false);
    REQUIRE(list.contains(47) == true);
}

TEST_CASE("remove and empty list", "[remove]") {
    Node::initialize_randomness();
    
    List list;
    list.insert(7);
    list.insert(48);
    list.insert(34);
    list.insert(20);

    list.remove(0);
    list.remove(1);
    list.remove(34);
    list.remove(34);
    list.remove(35);

    REQUIRE(list.contains(0) == false);
    REQUIRE(list.contains(7) == true);
    REQUIRE(list.contains(20) == true);
    REQUIRE(list.contains(34) == false);
    REQUIRE(list.contains(48) == true);
}

TEST_CASE("size", "[size]") {
    Node::initialize_randomness();
    
    List list;
    REQUIRE(list.size() == 0);
    
    list.insert(7);
    REQUIRE(list.size() == 1);
    
    list.insert(48);
    REQUIRE(list.size() == 2);
    
    list.insert(34);
    REQUIRE(list.size() == 3);
    
    list.insert(20);
    REQUIRE(list.size() == 4);

    list.insert(20);
    REQUIRE(list.size() == 4);

    list.remove(7);
    REQUIRE(list.size() == 3);
    
    list.remove(20);
    REQUIRE(list.size() == 2);

    list.insert(45);
    REQUIRE(list.size() == 3);
    
    list.remove(34);
    REQUIRE(list.size() == 2);
    
    list.remove(34);
    REQUIRE(list.size() == 2);
    
    list.remove(35);
    REQUIRE(list.size() == 2);
}