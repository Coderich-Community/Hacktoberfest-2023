
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Recursive
    ListNode* helper(ListNode* curr, ListNode* prev) {
        if (curr == NULL)
            return prev;
        ListNode* next = curr->next;
        curr->next = prev;
        return helper(next, curr);
    }

    ListNode* reverseListRecursive(ListNode* head) {
        return helper(head, NULL);
    }

    // Iterative
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedListFromArray(int arr[], int n) {
    if (n == 0)
        return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution solution;

    ListNode* head = createLinkedListFromArray(arr, n);

    cout << "Original Linked List: ";
    printLinkedList(head);

    ListNode* reversedRecursive = solution.reverseListRecursive(head);
    cout << "Reversed (Recursive) Linked List: ";
    printLinkedList(reversedRecursive);

    head = createLinkedListFromArray(arr, n); // Reset the linked list

    ListNode* reversedIterative = solution.reverseListIterative(head);
    cout << "Reversed (Iterative) Linked List: ";
    printLinkedList(reversedIterative);

    return 0;
}
