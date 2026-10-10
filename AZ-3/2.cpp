
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    if (head->val == head->next->val) {
        ListNode* duplicate = head->next;
        head->next = duplicate->next;
        delete duplicate;
        return deleteDuplicates(head);
    }

    head->next = deleteDuplicates(head->next);
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    head = deleteDuplicates(head);
    printList(head);
    return 0;
}
