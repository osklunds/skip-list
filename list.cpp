
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
    shared_ptr<Node> new_node = make_shared<Node>(0.25);
    new_node->set_value(value);
    int height = new_node->height();

    vector<shared_ptr<Node>> node_that_points_to_new_node_at_height;
    vector<shared_ptr<Node>> node_that_new_node_points_to_at_height;

    for (int i = 0; i < height; i++) {
        node_that_points_to_new_node_at_height.push_back(shared_ptr<Node>{});
        node_that_new_node_points_to_at_height.push_back(shared_ptr<Node>{});
    }


    shared_ptr<Node> current_node = head;

    while (true) {
        for (int i = current_node->height() - 1; i >= 0; i--) {
            shared_ptr<Node> next_node = current_node->get_next_node_at_index(i);


            if ((next_node == tail || value < next_node->get_value()) 
                && i > 0) {
                // The node we're looking for isn't beyond the next node
                // and we haven't reached the bottom yet.

                if (i < height) {
                    node_that_points_to_new_node_at_height[i] = current_node;
                    node_that_new_node_points_to_at_height[i] = next_node;
                }

                continue;
            } else if ((next_node == tail || value < next_node->get_value()) 
                && i == 0) {
                // The node we're looking for isn't beyond the next node
                // but we've reached the bottom.

                // Insert the node here.
                node_that_points_to_new_node_at_height[i] = current_node;
                node_that_new_node_points_to_at_height[i] = next_node;

                for (int j = 0; j < height; j++) {
                    //cout << j << ". pointing at new node: " << node_that_points_to_new_node_at_height[j]->get_value() << " pointed on by new node: " << node_that_new_node_points_to_at_height[j]->get_value() << endl;
                    node_that_points_to_new_node_at_height[j]->set_next_node_at_index(j, new_node);
                    new_node->set_next_node_at_index(j, node_that_new_node_points_to_at_height[j]);
                }

                return;
            } else if (value > next_node->get_value()) {
                // The node we're looking for is beyond the next node.
                current_node = next_node;
                break;
            } else {
                // The node is none of not beyond and beyond.
                // That means we've found the node.
                return;
            }
        }
    }
}

bool List::contains(int value) {
    shared_ptr<Node> current_node = head;

    while (true) {
        for (int i = current_node->height() - 1; i >= 0; i--) {
            shared_ptr<Node> next_node = current_node->get_next_node_at_index(i);

            if ((next_node == tail || value < next_node->get_value()) 
                && i > 0) {
                // The node we're looking for isn't beyond the next node
                // and we haven't reached the bottom yet.
                continue;
            } else if ((next_node == tail || value < next_node->get_value()) 
                && i == 0) {
                // The node we're looking for isn't beyond the next node
                // but we've reached the bottom.
                return false;
            } else if (value > next_node->get_value()) {
                // The node we're looking for is beyond the next node.
                current_node = next_node;
                break;
            } else {
                // The node is none of not beyond and beyond.
                // That means we've found the node.
                return true;
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