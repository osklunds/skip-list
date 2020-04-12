
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>

#include "node.h"

using namespace std;


int main() {
    srand(time(0));

    Node::initialize_randomness();

    Node n(0.25);

    for (int i = 0; i < n.next_nodes.size(); i++) {
        cout << (n.next_nodes[i] == NULL) << endl;
    }
}