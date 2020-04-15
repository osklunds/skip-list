
#include <iostream>
#include <memory>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    //Node::initialize_randomness();

    List list = List::example_list();

    list.remove(34);
    //list.remove(34);
    //list.remove(35);

    cout << list.contains(12) << endl;  


}