
#include <iostream>
#include <chrono>

#include "node.h"
#include "list.h"

using namespace std;


int main() {
    Node::initialize_randomness();
    srand(time(0));

    const int NUMBER_OF_INSERTS = 500;
    const int NUMBER_OF_CONTAINS = 1000;

    List list;

    for (int i = 0; i < NUMBER_OF_INSERTS; i++) {
        int number = rand();
        list.insert(number);
    }    

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < NUMBER_OF_CONTAINS; i++) {
        int number = rand();
        list.contains(number);
    }    

    auto end = chrono::high_resolution_clock::now();
    auto duration = (end-start) / chrono::milliseconds(1);


    cout << "On a list with " << list.size() << " number of elements, " << NUMBER_OF_CONTAINS << " contains took " << duration << " milliseconds." << endl;
}