#include <iostream>
#include <string>

using namespace std;

class ChainLink {
    private:
        string color;

    public:
        ChainLink(string color) {
            this->color = color;
        }

        string get_color() {
            return this->color;
        }
};

class Node {
    private:
        ChainLink* data;
        Node* next;

    public:
        Node(ChainLink* link) {
            data = link;
            next = nullptr;
        }

        void set_next(Node* next_node) {
            next = next_node;
        }

        Node* get_next() {
            return next;
        }

        ChainLink* get_data() {
            return data;
        }
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        void append(ChainLink* link) {
            Node* new_node = new Node(link);
            if (head == nullptr) {
                head = new_node;
            } else {
                Node* current = head;
                while (current->get_next() != nullptr) {
                    current = current->get_next();
                }
                current->set_next(new_node);
            }
        }

        ChainLink* view(int index) {
            Node* current = head;
            int count = 0;

            while (current != nullptr) {
                if (count == index) {
                    return current->get_data();
                }
                count++;
                current = current->get_next();
            }

            return nullptr;
        }
};

int main() {
    LinkedList list;

    ChainLink link_one("red");
    list.append(&link_one);

    ChainLink link_two("blue");
    list.append(&link_two);

    ChainLink link_three("green");
    list.append(&link_three);

    ChainLink* retrieved_link = list.view(1);
    if (retrieved_link != nullptr) {
        cout << "ChainLink at index 1: " << retrieved_link->get_color() << endl;
    } else {
        cout << "Index out of bounds" << endl;
    }
    
    ChainLink* another_retrieved_link = list.view(2);
    if (another_retrieved_link != nullptr) {
        cout << "ChainLink at index 2: " << another_retrieved_link->get_color() << endl;
    } else {
        cout << "Index out of bounds" << endl;
    }

    return 0;
}
