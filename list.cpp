
#include "list.h"

#include <iostream>


List::List() {
    head = make_shared<Node>(1);
    tail = make_shared<Node>(1);

    head->set_next_node_at_index(0, tail);
}

int List::size() {
    return 0;
}

void List::insert(int value) {

}

bool List::contains(int value) {
    shared_ptr<Node> current_node = head;

    while (true) {
        for (int i = current_node->height() - 1; i >= 0; i--) {
            if (current_node == tail) {
                return false;
            }

            shared_ptr<Node> next_node = current_node->get_next_node_at_index(i);

            if (next_node == tail) {
                if (i > 0) {
                    continue;
                } else {
                    return false;
                }
            }

            if (value == next_node->get_value()) {
                return true;
            } else if (value > next_node->get_value()) {
                current_node = next_node;
                break;
            } else if (value < next_node->get_value() && i > 0) {
                continue;
            } else { // value < next_node->get_value() && i == 0
                return false;
            }
        }
    }
}

void List::remove(int value) {

}

/*
Index:  H  0  1  2  3  4  T
Height: 6  1  3  2  4  2  6

5       =                 =
4       =                 =
3       =           =     =
2       =     =     =     =
1       =     =  =  =  =  =
0       =  =  =  =  =  =  =
Value:  -  12 18 19 34 47 -
*/
List List::example_list() {
    List list;

    auto n0 = make_shared<Node>(1);
    n0->set_value(12);

    auto n1 = make_shared<Node>(3);
    n1->set_value(18);

    auto n2 = make_shared<Node>(2);
    n2->set_value(19);

    auto n3 = make_shared<Node>(4);
    n3->set_value(34);

    auto n4 = make_shared<Node>(2);
    n4->set_value(47);

    list.head->increase_height_to(6);
    list.tail->increase_height_to(6);

    list.head->set_next_node_at_index(0, n0);
    list.head->set_next_node_at_index(1, n1);
    list.head->set_next_node_at_index(2, n1);
    list.head->set_next_node_at_index(3, n3);
    list.head->set_next_node_at_index(4, list.tail);
    list.head->set_next_node_at_index(5, list.tail);

    n0->set_next_node_at_index(0, n1);

    n1->set_next_node_at_index(0, n2);
    n1->set_next_node_at_index(1, n2);
    n1->set_next_node_at_index(2, n3);

    n2->set_next_node_at_index(0, n3);
    n2->set_next_node_at_index(1, n3);

    n3->set_next_node_at_index(0, n4);
    n3->set_next_node_at_index(1, n4);
    n3->set_next_node_at_index(2, list.tail);
    n3->set_next_node_at_index(3, list.tail);

    n4->set_next_node_at_index(0, list.tail);
    n4->set_next_node_at_index(1, list.tail);

    return list;
}