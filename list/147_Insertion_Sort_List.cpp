/*
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if((!head)||(!head->next)) {
            return head;
        }
        ListNode *curr = head->next;
        ListNode *curr_prev = head;
        ListNode ph(0);
        ph.next = head;
        while(curr) {
            ListNode *tmp = ph.next;
            ListNode *tmp_prev = &ph;
            while(tmp != curr) {
                if(tmp->val > curr->val) {
                    tmp_prev->next = curr;
                    curr_prev->next = curr->next;
                    curr->next = tmp;
                    curr = curr_prev;
                    break;
                }
                tmp_prev = tmp;
                tmp = tmp->next;
            }
            curr_prev = curr;
            curr = curr->next;
        }
        head = ph.next;
        return head;
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
    vector<int> x = {5,6,3,2};
    ListNode *head = create_list(x);
    ListNode *tmp = head;
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    Solution slt;
    head = slt.insertionSortList(head);
    tmp = head;
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
