/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ph(0);
        ListNode *nd = &ph;
        int c = 0;
        while(l1&&l2) {
            nd->next = new ListNode((l1->val + l2->val + c) % 10);
            c = (l1->val + l2->val + c) / 10;
            nd = nd->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l = (l1) ? l1 : l2;
        while(l) {
            nd->next = new ListNode((l->val + c) % 10);
            c = (l->val + c) / 10;
            nd = nd->next;
            l = l->next;
        }
        if(c > 0) {
            nd->next = new ListNode(c);
        }
        return ph.next;
    }
};


ListNode *create_list(vector<int> &input) {
    ListNode *node = new ListNode(input[0]);
    ListNode *prev = node;
    ListNode *head = node;
    for(int i = 1; i < input.size(); i++) {
        node = new ListNode(input[i]);
        prev->next = node;
        prev = node;
    }
    return head;
}

void printList(ListNode *head) {
    while(head) {
        cout<<head->val<<", ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    vector<int> x1 = {7,3,2,5,1,8};
    vector<int> x2 = {7,3,2,5,1,8};
    ListNode* head1 = create_list(x1);
    ListNode* head2 = create_list(x2);
    printList(head1);
    printList(head2);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.addTwoNumbers(head1, head2);
    printList(head);
}
