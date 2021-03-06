
#pragma once

#include <memory>
#include <vector>
#include <random>

using namespace std;


class Node {
//public:
private:
    static mt19937 generator;
    static uniform_real_distribution<> distribution;
    static int get_a_height(double probability);

    vector<shared_ptr<Node>> next_nodes;

    int value;
public:
    static void initialize_randomness();

    Node(double probability);
    Node(int height);
    void initialize_next_nodes(int height);

    int height();
    void increase_height_to(int new_height);
    shared_ptr<Node> get_next_node_at_index(int index);
    void set_next_node_at_index(int index, shared_ptr<Node> node);

    int get_value();
    void set_value(int value);
};