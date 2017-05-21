/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Subscribe to see which companies asked this question.
*/
#include <iostream>
#include <sstream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ret = 0;
        travel(root->left, root, ret);
        travel(root->right, root, ret);
        return ret;
    }
private:
    void travel(TreeNode *root, TreeNode *parent, int &ret) {
        if(!root) {
            return;
        }
        if((!root->left)&&(!root->right)) {
            if(root == parent->left) {
                ret += root->val;
            }
            return;
        }
        travel(root->left, root, ret);
        travel(root->right, root, ret);
    }
};

class BSTree {
public:
    BSTree():root(nullptr),size(0) {}
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
    if(!root) {
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
    //[4,3,6,2,4,6,7,null,null,4,4,6]
    vector<int> input = {10,5,7,3,2,1,12};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;

    Solution slt;
    cout<<slt.sumOfLeftLeaves(tree.root)<<endl;
    return 0;
}
