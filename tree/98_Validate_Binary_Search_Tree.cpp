/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/
#include <iostream>
#include <vector>
#include <limits>

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
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        //使用long避免遇到INT_MIN和INT_MAX的错误
        return isInRange(root->left, std::numeric_limits<long>::min(), (long)root->val)
                &&isInRange(root->right, (long)root->val, std::numeric_limits<long>::max());
    }
private:
    bool isInRange(TreeNode* root, long min, long max) {
        if(!root) {
            return true;
        }
        if((root->val > min)&&(root->val < max)) {
            return isInRange(root->left, min, root->val)
                    &&isInRange(root->right, root->val, max);
        }
        return false;
    }
    /*
    bool travel(TreeNode *root, int val, std::function<bool(int, int)> f) {
        if(!root) {
            return true;
        }
        if(f(root->val, val)) {
            return false;
        }
        return travel(root->left, val, f) && travel(root->right, val, f);
    }

    bool travelRight(TreeNode *root, int val) {
        if(!root) {
            return true;
        }
        if(root->val <= val) {
            return false;
        }
        return travelRight(root->left, val) && travelRight(root->right, val);
    }*/
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
    vector<int> input = {6,3,1,0,4,8,9};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    bool ret = slt.isValidBST(tree.root);
    cout<<ret<<endl;
    return 0;
}
