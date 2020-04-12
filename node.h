
#pragma once

#include <memory>
#include <vector>
#include <random>

using namespace std;


class Node {
public:
//private:
    static mt19937 generator;
    static uniform_real_distribution<> distribution;

    vector<unique_ptr<Node> > next_nodes;

    int get_a_height(double probability);

public:
    static void initialize_randomness();

    Node(double probability);
};