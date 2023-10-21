#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
public:
    Node* head;

  
    LinkedList() {
        head = nullptr;
    }

    //  insert a new element at the beginning of the linked list.
    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // display the linked list elements.
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> "; 
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // reverse the linked list.
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        // Traverse the list
        while (current != nullptr) {
            nextNode = current->next;  
            current->next = prev;     
            prev = current;           
            current = nextNode;       
        }

        head = prev; // Set the new head.
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
