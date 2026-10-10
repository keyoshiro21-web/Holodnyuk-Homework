
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->val <= b->val) {
        a->next = mergeTwoLists(a->next, b);
        return a;
    }

    b->next = mergeTwoLists(a, b->next);
    return b;
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
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    printList(mergeTwoLists(a, b));
    return 0;
}
