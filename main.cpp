
#include <iostream>
#include <memory>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    Node::initialize_randomness();

    List list = List::example_list();

    for (auto it = list.begin(); it != list.end(); it++) {
        cout << *it << endl;
    }

    
}