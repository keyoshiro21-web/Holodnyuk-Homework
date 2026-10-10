#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycleHelper(ListNode* slow, ListNode* fast) {
    if (fast == nullptr || fast->next == nullptr) {
        return false;
    }

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
        return true;
    }

    return hasCycleHelper(slow, fast);
}

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    return hasCycleHelper(head, head);
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;

    if (hasCycle(head)) {
        cout << "Список містить цикл" << endl;
    } else {
        cout << "Список не містить циклу" << endl;
    }

    return 0;
}