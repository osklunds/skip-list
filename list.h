
#pragma once

#include <memory>

#include "node.h"


class List {
private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    int _size;

    void check_invariants();
    void check_head_tail_same_height();
    void check_tail_points_to_null();
    void check_strictly_increasing_non_null();
    void check_next_has_sufficient_height();
    void check_next_is_first_of_its_height();
    void check_size();

    template<typename T>
    bool find(T find_helper);

public:
    List();
    ~List();

    int size();
    void insert(int value);
    bool contains(int value);
    void remove(int value);

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