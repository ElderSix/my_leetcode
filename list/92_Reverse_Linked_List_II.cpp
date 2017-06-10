/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) {
            return head;
        }

        ListNode ph(0);
        ph.next = head;

        ListNode* p = &ph;
        ListNode* t = head;
        for(int i = 1; i < n; i++) {
            if(i < m) {
                p = p->next;
                t = t->next;
                continue;
            }
            ListNode* tmp = t->next;
            t->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
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
    vector<int> x1 = {1,2,3,4,5,6,7};
    ListNode* head1 = create_list(x1);
    printList(head1);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.reverseBetween(head1, 1, 7);
    printList(head);
}
