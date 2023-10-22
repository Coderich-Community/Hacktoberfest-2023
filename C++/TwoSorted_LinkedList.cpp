#include <iostream>

// Define a struct for a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Create a dummy node as the head of the merged list
    ListNode dummy(0);
    ListNode* current = &dummy;

    // Iterate through the input lists
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // If one of the lists is exhausted, append the remaining list
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return dummy.next; // The merged list starts from the next of the dummy node
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
