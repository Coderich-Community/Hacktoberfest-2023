#include <iostream>

// Define a doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to insert a node at the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to print the list in forward direction
    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to print the list in reverse direction
    void printReverse() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    DoublyLinkedList dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    std::cout << "Doubly Linked List (Forward): ";
    dll.printForward();

    std::cout << "Doubly Linked List (Reverse): ";
    dll.printReverse();

    dll.prepend(0);

    std::cout << "Doubly Linked List after prepending 0 (Forward): ";
    dll.printForward();

    return 0;
}
