
#include <iostream>
#include <memory>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    //Node::initialize_randomness();

    List list = List::example_list();
    list.insert(7);
    list.insert(48);
    list.insert(34);
    list.insert(20);
}