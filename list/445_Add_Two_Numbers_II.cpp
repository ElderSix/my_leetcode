/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
        //先将两个链表补到一样长，然后递归
        //还有一种方法是建立两个栈，把链表元素入栈，然后逐个出栈相加
        ListNode* l1tmp = l1;
        ListNode* l2tmp = l2;
        int diff = compareLenth(l1, l2);
        (diff > 0) ? (l2tmp = addPadding(l2, diff)) : (l1tmp = addPadding(l1, -diff));
        ListNode* sum_head = new ListNode(0);
        int c = 0;
        addTwoNumberRecur(l1tmp, l2tmp, sum_head, c);
        ListNode* result;
        if(c > 0) {
            sum_head->val += c;
            result = sum_head;
        }else {
            result = sum_head->next;
            delete sum_head;
        }
        deletePadding(l1tmp, l1);
        deletePadding(l2tmp, l2);
        return result;
    }
private:
    int compareLenth(ListNode* l1, ListNode* l2) {
        int l1_len = 0;
        int l2_len = 0;
        while(l1) {
            l1_len++;
            l1 = l1->next;
        }
        while(l2) {
            l2_len++;
            l2 = l2->next;
        }
        return l1_len - l2_len;
    }
    ListNode* addPadding(ListNode* l, int diff) {
        ListNode* node;
        while(diff > 0) {
            node = new ListNode(0);
            node->next = l;
            l = node;
            diff--;
        }
        return l;
    }
    void deletePadding(ListNode* l, ListNode* org) {
        ListNode* node;
        while(l != org) {
            node = l;
            l = l->next;
            delete node;
        }
    }
    void addTwoNumberRecur(ListNode* l1, ListNode* l2, ListNode* result, int& c) {
        if((!l1)&&(!l2)) {
            return;
        }
        if((l1)&&(l2)) {
            addTwoNumberRecur(l1->next, l2->next, result, c);
            ListNode* node = new ListNode((l1->val + l2->val + c) % 10);
            c = (l1->val + l2->val + c) / 10;
            node->next = result->next;
            result->next = node;
            return;
        }
        if(!l1) {
            addTwoNumberRecur(l1, l2->next, result, c);
        }else {
            addTwoNumberRecur(l1->next, l2, result, c);
        }
        return;
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
    vector<int> x1 = {9,6,9,9};
    vector<int> x2 = {8,1,1};
    ListNode* head1 = create_list(x1);
    ListNode* head2 = create_list(x2);

    Solution slt;
    ListNode* head = slt.addTwoNumbers(head1, head2);
    printList(head);
}
