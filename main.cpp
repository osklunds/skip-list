
#include <iostream>
#include <memory>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    Node::initialize_randomness();

    List list = List::example_list();

    cout << list.contains(0) << endl;
}