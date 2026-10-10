
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* second = head->next;
    head->next = swapPairs(second->next);
    second->next = head;

    return second;
}

void printList(ListNode* head) {
    if (head == nullptr) {
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

    head = swapPairs(head);
    printList(head);

    return 0;
}
