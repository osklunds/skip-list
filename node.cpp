
#include "node.h"

#include <iostream>
#include <cassert>

mt19937 Node::generator;
uniform_real_distribution<> Node::distribution;


void Node::initialize_randomness() {
    random_device rd;
    generator = mt19937(rd());
    distribution = uniform_real_distribution<double>(0.0, 1.0);
}

int Node::get_a_height(double probability) {
    int height = 1;

    while (true) {
        double random_number = distribution(generator);
        if (random_number > probability) {
            height++;
        } else {
            break;
        }
    }

    return height;
}

Node::Node(double probability) {
    int height = get_a_height(probability);
    initialize_next_nodes(height);
}

Node::Node(int height) {
    initialize_next_nodes(height);
}

void Node::initialize_next_nodes(int height) {
    for (int i = 0; i < height; i++) {
        next_nodes.push_back(shared_ptr<Node>{});
    }
}

int Node::height() {
    return next_nodes.size();
}

void Node::increase_height_to(int new_height) {
    int extra_height = new_height - height();
    assert(extra_height > 0);

    for (int i = 0; i < extra_height; i++) {
        next_nodes.push_back(shared_ptr<Node>{});
    }
}

shared_ptr<Node> Node::get_next_node_at_index(int index) {
    return next_nodes[index];
}

void Node::set_next_node_at_index(int index, shared_ptr<Node> node) {
    next_nodes[index] = node;
}

int Node::get_value() {
    return value;
}

void Node::set_value(int value) {
    this->value = value;
}