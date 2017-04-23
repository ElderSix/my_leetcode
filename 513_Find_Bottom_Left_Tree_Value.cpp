/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int val = root->val;
        int max_level = 0;
        travel(root, 0, &max_level, &val);
        return val;
    }
private:
    void travel(TreeNode *root, int level, int *max_level, int *val) {
        if((!root->left)&&(!root->right)) {
            if(level > *max_level) {
                *max_level = level;
                *val = root->val;
            }
            return;
        }
        if(root->left) {
            travel(root->left, level+1, max_level, val);
        }
        if(root->right) {
            travel(root->right, level+1, max_level, val);
        }
    }
};

class BSTree {
public:
    BSTree():size(0),root(nullptr) {}
    int insert(int d);
    TreeNode* search(int d, TreeNode** parent);
    int deleteNode(TreeNode* node);
    void print();
    TreeNode* root;
private:
    int size;
    void do_print(TreeNode* begin);
};

int BSTree::insert(int d) {
    TreeNode* pnode = nullptr;
    TreeNode* new_node = new TreeNode(d);
    TreeNode* node = search(d, &pnode);
    if(!pnode) {
        root = new_node;
        return 0;
    }
    if(!node) {
        if(d <= pnode->val) {
            pnode->left = new_node;
        }else {
            pnode->right = new_node;
        }
    }else {
        new_node->left = node->left;
        node->left = new_node;
    }

    return 0;
}

TreeNode* BSTree::search(int d, TreeNode** parent) {
    TreeNode *begin = root;
    while((begin != nullptr) && (begin->val != d)) {
        *parent = begin;
        begin = (begin->val < d) ? begin->right : begin->left;
    }   //Find the first one
    return begin;
}

void BSTree::print() {
    do_print(root);
}

void BSTree::do_print(TreeNode* begin) {
    if(!begin) {
        return;
    }
    cout<<"[";
    do_print(begin->left);
    cout<<" "<<begin->val<<" ";
    do_print(begin->right);
    cout<<"]";
    return;
}

int main() {
    BSTree tree;
    vector<int> input = {9,2,1,6,3,5,8};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    int result = slt.findBottomLeftValue(tree.root);
    cout<<result<<endl;
}
