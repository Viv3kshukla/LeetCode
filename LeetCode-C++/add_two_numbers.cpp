#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/add-two-numbers

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *preNode = new ListNode();
        ListNode *p = preNode;
        int carry = 0, sum = 0;
        while (l1 || l2 || carry) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preNode->next;
    }
};

void printList(ListNode *x) {
    while (x != nullptr) {
        cout << x->val << " ";
        x = x->next;
    }
    cout << endl;
}

// mock
int main() {
    ListNode *head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    Solution m;
    ListNode *ans = m.addTwoNumbers(head1, head1);
    printList(ans);
    return 0;
}