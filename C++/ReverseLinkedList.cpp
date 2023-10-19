#include <iostream>

// Define a linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link
        
        // Move to the next nodes
        prev = current;
        current = next;
    }
    
    return prev;  // 'prev' is the new head of the reversed list
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    std::cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}

