
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int doubleRec(ListNode* node) {
    if (!node) return 0;

    int carry = doubleRec(node->next);
    int value = node->val * 2 + carry;

    node->val = value % 10;
    return value / 10;
}

ListNode* doubleIt(ListNode* head) {
    int carry = doubleRec(head);

    if (carry > 0) {
        ListNode* newHead = new ListNode(carry);
        newHead->next = head;
        return newHead;
    }

    return head;
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
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    head = doubleIt(head);
    printList(head);
    return 0;
}
