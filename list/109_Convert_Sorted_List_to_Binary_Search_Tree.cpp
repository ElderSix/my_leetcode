/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
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

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode left_head(0);
        left_head.next = head;

        ListNode *slow = &left_head;
        ListNode *fast = head;

        while((fast->next)&&(fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode *tree_head = new TreeNode(slow->next->val);
        ListNode *right_head = slow->next->next;

        slow->next = nullptr;
        //left_head.next point to head, or null(when head->next is null)
        tree_head->left = sortedListToBST(left_head.next);
        tree_head->right = sortedListToBST(right_head);
        return tree_head;
    }
};

void print_BST(TreeNode *head) {
    if(!head) {
        return;
    }
    cout<<"[";
    print_BST(head->left);
    cout<<" "<<head->val<<" ";
    print_BST(head->right);
    cout<<"]";
    return;
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

int main() {
    vector<int> x = {1};
    ListNode *head = create_list(x);
    ListNode *tmp = head;
    while(tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    Solution slt;
    TreeNode *tree_head = slt.sortedListToBST(head);
    print_BST(tree_head);
    cout<<endl;
}
