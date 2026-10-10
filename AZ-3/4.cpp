
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void mergeLists(ListNode* a, ListNode* b) {
    if (!a || !b) return;

    ListNode* nextA = a->next;
    ListNode* nextB = b->next;

    a->next = b;
    b->next = nextA;

    mergeLists(nextA, nextB);
}

void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = reverseList(slow->next);
    slow->next = nullptr;

    mergeLists(head, second);
}

void printList(ListNode* head) {
    if (!head) {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    printList(head->next);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    reorderList(head);
    printList(head);
    return 0;
}
