
#pragma once

#include <memory>

#include "node.h"


class List {
private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    int _size;

    void check_invariants();
    template<typename T>
    bool find(T find_helper);

public:
    List();

    int size();
    void insert(int value);
    bool contains(int value);
    void remove(int value);
    // TODO: Iterator

    static List example_list();

    class Iterator {
    private:
        shared_ptr<Node> current;
        shared_ptr<Node> tail;

    public:
        Iterator(shared_ptr<Node> head, shared_ptr<Node> tail);
        Iterator& operator++();
        Iterator operator++(int);
        int operator*();
        bool operator==(const Iterator &other);
        bool operator!=(const Iterator &other);
    };

    Iterator begin();
    Iterator end();
};