
#include "list.h"


List::List() {
    head = make_shared<Node>(1);
    tail = make_shared<Node>(1);

    head->set_next_node_at_index(0, tail);
}

int List::size() {
    return 0;
}

void insert(int value) {

}

bool contains(int value) {
    return false;
}

void remove(int value) {

}
