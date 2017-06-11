/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if((k == 0)||(!head)) {
            return head;
        }
        ListNode* fast = head;

        int list_len = 0;
        while(fast) {
            list_len++;
            fast = fast->next;
        }
        k = k % list_len;
        if(k == 0) {
            return head;
        }

        ListNode ph(0);
        ph.next = head;
        ListNode* slow = &ph;
        fast = head;
        while(fast->next) {
            k--;
            fast = fast->next;
            if(k < 1) {
                slow = slow->next;
            }
        }

        if(ph.next != slow->next) {
            fast->next = ph.next;
            ph.next = slow->next;
            slow->next = nullptr;
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
    ListNode* head1 = create_list(x1);
    printList(head1);
    cout<<"start"<<endl;
    Solution slt;
    ListNode* head = slt.rotateRight(head1, 13);
    printList(head);
}
