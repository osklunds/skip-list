
#pragma once

#include <memory>

#include "node.h"


class List {
//private:
public:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
public:
    List();

    int size();
    void insert(int value);
    bool contains(int value);
    void remove(int value);
    // TODO: Iterator
};