
#include "list.h"

#include <iostream>


// TODO: Refactor into a common while-for loop, that can
// contain diffrent logic through lambdas.
// Also make many smaller functions for the various tests.
void List::check_invariants() {
    // head and tail have the same height
    assert(head->height() == tail->height());

    // Everything tail points to is NULL
    for (int i = 0; i < tail->height(); i++) {
        assert(tail->get_next_node_at_index(i) == NULL);
    }

    // Also detects cycles. That's why it's placed earlier
    auto current_node = head;
    while (current_node != tail) {
        for (int i = 0; i < current_node->height(); i++) {
            // Everyhing a non-tail points to is non-NULL
            auto next_node = current_node->get_next_node_at_index(i);
            assert(next_node != NULL);

            if (current_node != head && next_node != tail) {
                // Everything a node points to is larger than itself
                assert(current_node->get_value() < next_node->get_value());
            }
        }

        current_node = current_node->get_next_node_at_index(0);
    }
    
    current_node = head;

    while (current_node != tail) {
        //cout << "current node: " << current_node->get_value() << endl;

        for (int i = 0; i < current_node->height(); i++) {
            // Everyhing a non-tail points to is non-NULL
            auto next_node = current_node->get_next_node_at_index(i);

            //cout << "h: " << i << "   next node: " << next_node->get_value() << endl;
            
            // That what points at has height at least that height index.
            assert(next_node->height() > i);

            // That next node is the first node of height i
            auto bottom_neighbor = current_node->get_next_node_at_index(0);
            //cout << "bottom: " << bottom_neighbor->get_value() << endl;
            while (bottom_neighbor != next_node) {
                assert(bottom_neighbor->height() <= i);
                bottom_neighbor = bottom_neighbor->get_next_node_at_index(0);
                //cout << "bottom: " << bottom_neighbor->get_value() << endl;
            }
        }
        current_node = current_node->get_next_node_at_index(0);
    }

    // That size is correct
    current_node = head;
    int size = 0;
    while (current_node->get_next_node_at_index(0) != tail) {
        current_node = current_node->get_next_node_at_index(0);
        size++;
    }

    assert(this->size() == size);
}


List::List() {
    head = make_shared<Node>(1);
    tail = make_shared<Node>(1);

    head->set_next_node_at_index(0, tail);

    _size = 0;
}

int List::size() {
    return _size;
}

template<typename T>
bool List::find(T find_helper) {
    shared_ptr<Node> current_node = head;

    while (true) {
        for (int i = current_node->height() - 1; i >= 0; i--) {
            shared_ptr<Node> next_node = current_node->get_next_node_at_index(i);

            if ((next_node == tail || find_helper.value() < next_node->get_value()) 
                && i > 0) {
                // The node we're looking for isn't beyond the next node
                // and we haven't reached the bottom yet.

                find_helper.at_level_node_between_current_and_next(i, current_node, next_node);

                continue;
            } else if ((next_node == tail || find_helper.value() < next_node->get_value()) 
                && i == 0) {
                // The node we're looking for isn't beyond the next node
                // but we've reached the bottom.

                find_helper.at_bottom_node_between_current_and_next(current_node, next_node);

                return false;
            } else if (find_helper.value() > next_node->get_value()) {
                // The node we're looking for is beyond the next node.
                current_node = next_node;
                break;
            } else {
                // The node is none of not beyond and beyond.
                // That means we've found the node.

                if (find_helper.at_level_node_is_next(i, current_node, next_node)) {
                    return true;
                }
            }
        }
    }
}

void List::insert(int value) {
    class FindHelper {
    private:
        List &list;
        int _value;

        shared_ptr<Node> new_node;

        vector<shared_ptr<Node>> node_that_points_to_new_node_at_height;
        vector<shared_ptr<Node>> node_that_new_node_points_to_at_height;
    public:
        FindHelper(List &list, int value) : list(list), _value(value) {
            new_node = make_shared<Node>(0.25);
            new_node->set_value(value);
            int height = new_node->height();

            int old_height = list.head->height();
            if (height > old_height) {
                list.head->increase_height_to(height);
                list.tail->increase_height_to(height);

                for (int i = old_height; i < list.head->height(); i++) {
                    list.head->set_next_node_at_index(i, list.tail);
                }
            }

            for (int i = 0; i < height; i++) {
                node_that_points_to_new_node_at_height.push_back(shared_ptr<Node>{});
                node_that_new_node_points_to_at_height.push_back(shared_ptr<Node>{});
            }
        }

        int value() {
            return _value;
        }

        void at_level_node_between_current_and_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {
            if (i < new_node->height()) {
                node_that_points_to_new_node_at_height[i] = current_node;
                node_that_new_node_points_to_at_height[i] = next_node;
            }
        }

        void at_bottom_node_between_current_and_next(shared_ptr<Node> current_node, shared_ptr<Node> next_node) {
            node_that_points_to_new_node_at_height[0] = current_node;
            node_that_new_node_points_to_at_height[0] = next_node;

            for (int j = 0; j < new_node->height(); j++) {
                //cout << j << ". pointing at new node: " << node_that_points_to_new_node_at_height[j]->get_value() << " pointed on by new node: " << node_that_new_node_points_to_at_height[j]->get_value() << endl;
                node_that_points_to_new_node_at_height[j]->set_next_node_at_index(j, new_node);
                new_node->set_next_node_at_index(j, node_that_new_node_points_to_at_height[j]);
            }

            list._size++;
        }

        bool at_level_node_is_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {
            return true;
        }
    };

    FindHelper find_helper(*this, value);
    find(find_helper);

    check_invariants();
    assert(contains(value));
}

bool List::contains(int value) {
    class FindHelper {
    private:
        int _value;

    public:
        FindHelper(int value) {
            _value = value;
        }

        int value() {
            return _value;
        }

        void at_level_node_between_current_and_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {};

        void at_bottom_node_between_current_and_next(shared_ptr<Node> current_node, shared_ptr<Node> next_node) {};

        bool at_level_node_is_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {
            return true;
        }
    };

    FindHelper find_helper(value);
    return find(find_helper);
}

void List::remove(int value) {
    class FindHelper {
    private:
        List &list;
        int _value;

        vector<shared_ptr<Node>> node_that_points_to_old_node_at_height;
        vector<shared_ptr<Node>> node_that_old_node_points_to_at_height;

    public:
        FindHelper(List &list, int value) : list(list) {
            _value = value;

            for (int i = 0; i < list.head->height(); i++) {
                node_that_points_to_old_node_at_height.push_back(shared_ptr<Node>{});
                node_that_old_node_points_to_at_height.push_back(shared_ptr<Node>{});
            }
        }

        int value() {
            return _value;
        }

        void at_level_node_between_current_and_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {};

        void at_bottom_node_between_current_and_next(shared_ptr<Node> current_node, shared_ptr<Node> next_node) {};

        bool at_level_node_is_next(int i, shared_ptr<Node> current_node, shared_ptr<Node> next_node) {
            //cout << "at_level_node_is_next " << i << " " << current_node->get_value() << " " << next_node->get_value() << endl;

            // Redirect to the next node past the node to remove.
            // But only as long as the current node points to the node
            // to remove.
            for (int j = i; j >= 0; j--) {
                if (current_node->get_next_node_at_index(j) != next_node) {
                    break;
                }

                current_node->set_next_node_at_index(j, next_node->get_next_node_at_index(j));

                if (j == 0) {
                    list._size --;
                }
            }

            return false;
        }
    };

    FindHelper find_helper(*this, value);
    find(find_helper);

    check_invariants();
    assert(!contains(value));
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

    list._size = 5;

    list.check_invariants();

    return list;
}