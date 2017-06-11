/*

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode ph(0);
        ph.next = head;
        ListNode* t = &ph;
        ListNode large_head(0);
        ListNode* large_end = &large_head;

        while(t->next) {
            if(t->next->val >= x) {
                large_end->next = t->next;
                large_end = large_end->next;
                t->next = large_end->next;
            }else {
                t = t->next;
            }
        }
        t->next = large_head.next;
        large_end->next = nullptr;
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
    ListNode* head1 = create_list(x1);
    printList(head1);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.partition(head1, 3);
    printList(head);
}
