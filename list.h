
#pragma once

#include <memory>

#include "node.h"


class List {
private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    void check_invariants();
public:
    List();

    int size();
    void insert(int value);
    bool contains(int value);
    void remove(int value);
    // TODO: Iterator

    static List example_list();
};