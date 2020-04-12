
#include "node.h"

#include <iostream>

mt19937 Node::generator;
uniform_real_distribution<> Node::distribution;


void Node::initialize_randomness() {
    random_device rd;
    generator = mt19937(rd());
    distribution = uniform_real_distribution(0.0, 1.0);
}

Node::Node(double probability) {
    int height = this->get_a_height(probability);

    for (int i = 0; i < height; i++) {
        this->next_nodes.push_back(unique_ptr<Node>{});
    }
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