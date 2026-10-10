
#include <iostream>
#include <vector>
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

ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) return lists[left];

    int mid = left + (right - left) / 2;

    ListNode* a = mergeRange(lists, left, mid);
    ListNode* b = mergeRange(lists, mid + 1, right);

    return mergeTwoLists(a, b);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeRange(lists, 0, (int)lists.size() - 1);
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
    vector<ListNode*> lists(3);

    lists[0] = new ListNode(1);
    lists[0]->next = new ListNode(4);
    lists[0]->next->next = new ListNode(5);

    lists[1] = new ListNode(1);
    lists[1]->next = new ListNode(3);
    lists[1]->next->next = new ListNode(4);

    lists[2] = new ListNode(2);
    lists[2]->next = new ListNode(6);

    printList(mergeKLists(lists));
    return 0;
}
