
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getKth(ListNode* head, int k) {
    if (!head || k == 0) return head;
    return getKth(head->next, k - 1);
}

ListNode* reversePart(ListNode* head, int k, ListNode* prev) {
    if (k == 0) return prev;

    ListNode* next = head->next;
    head->next = prev;

    return reversePart(next, k - 1, head);
}

int countNodes(ListNode* head) {
    if (!head) return 0;
    return 1 + countNodes(head->next);
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;

    if (countNodes(head) < k) return head;

    ListNode* nextGroup = getKth(head, k);
    ListNode* newHead = reversePart(head, k, nextGroup);

    head->next = reverseKGroup(nextGroup, k);

    return newHead;
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

    printList(reverseKGroup(head, 2));
    return 0;
}
