
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void partitionRec(
    ListNode* node, int x,
    ListNode*& lessHead, ListNode*& lessTail,
    ListNode*& greaterHead, ListNode*& greaterTail
) {
    if (!node) return;

    ListNode* next = node->next;
    node->next = nullptr;

    if (node->val < x) {
        if (!lessHead) {
            lessHead = lessTail = node;
        } else {
            lessTail->next = node;
            lessTail = node;
        }
    } else {
        if (!greaterHead) {
            greaterHead = greaterTail = node;
        } else {
            greaterTail->next = node;
            greaterTail = node;
        }
    }

    partitionRec(next, x, lessHead, lessTail,
                 greaterHead, greaterTail);
}

ListNode* partition(ListNode* head, int x) {
    ListNode* lessHead = nullptr;
    ListNode* lessTail = nullptr;
    ListNode* greaterHead = nullptr;
    ListNode* greaterTail = nullptr;

    partitionRec(head, x, lessHead, lessTail,
                 greaterHead, greaterTail);

    if (!lessHead) return greaterHead;

    lessTail->next = greaterHead;
    return lessHead;
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
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    printList(partition(head, 3));
    return 0;
}
