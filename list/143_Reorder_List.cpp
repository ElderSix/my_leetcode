/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        ListNode **head_pt = &head;
        travel(head, head_pt);
    }
private:
    ListNode *travel(ListNode *curr, ListNode **head_pt) {
        if((curr)&&(curr->next)) {
            ListNode *node = travel(curr->next, head_pt);
            //do sth.
            if(!node) {
                return nullptr;
            }
            if(((*head_pt)->next == node)||((*head_pt) == node)) {
                node->next = nullptr;
                return nullptr;
            }
            node->next = (*head_pt)->next;
            (*head_pt)->next = node;
            *head_pt = node->next;
        }
        return curr;
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
int main() {
    vector<int> x = {1,3};
    ListNode *head = create_list(x);
    ListNode *tmp = head;
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    Solution slt;
    slt.reorderList(head);
    cout<<"reorder finished"<<endl;
    tmp = head;
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
