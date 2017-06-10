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
    ListNode *detectCycle(ListNode *head) {
        if(!head) {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *ret = nullptr;
        while((fast->next)&&(fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                ret = slow;
                break;
            }
        }
        return ret;
    }
};

void make_circle(ListNode* head, int k) {
    ListNode *tmp = head;
    while(k > 0) {
        k--;
        head = head->next;
    }
    tmp = head;
    while(head->next) {
        head = head->next;
    }
    head->next = tmp;
}

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
    make_circle(head1, 4);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.detectCycle(head1);
    if(head) {
        cout<<head->val<<endl;
    }
    cout<<"end"<<endl;
}
