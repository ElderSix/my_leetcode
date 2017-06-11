/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode ph(0);
        ph.next = head;
        ListNode* prev = &ph;
        ListNode* tmp = nullptr;
        while((prev->next)&&(prev->next->next)) {
            if(prev->next->val == prev->next->next->val) {
                int dup_val = prev->next->val;
                tmp = prev->next;
                while((tmp)&&(tmp->val == dup_val)) {
                    prev->next = tmp->next;
                    delete tmp;
                    tmp = prev->next;
                }
            }else {
                prev = prev->next;
            }
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
    vector<int> x1 = {1,1,2,2,3,3,4,5,5,5};
    ListNode* head1 = create_list(x1);
    printList(head1);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.deleteDuplicates(head1);
    printList(head);
}
