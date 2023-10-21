#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

int main() {
    ListNode *commonNode = new ListNode(7);
    commonNode->next = new ListNode(8);
    commonNode->next->next = new ListNode(9);

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = commonNode;

    ListNode *list2 = new ListNode(3);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(5);
    list2->next->next->next = commonNode;

    ListNode *intersectionNode = getIntersectionNode(list1, list2);

    if (intersectionNode != nullptr)
        cout << "Intersection at node with value " << intersectionNode->val << endl;
    else
        cout << "No intersection found" << endl;

    // Clean up memory (optional)
    delete list1;
    delete list2;

    return 0;
}
