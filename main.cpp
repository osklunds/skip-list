
#include <iostream>
#include <memory>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    Node::initialize_randomness();

    List list;
    list.insert(19);

    cout << list.contains(19) << endl;
}