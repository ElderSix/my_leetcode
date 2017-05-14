/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and
node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this
node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/
#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        deque<TreeNode*> unvisited;
        unvisited.push_back(s);
        TreeNode *node;
        while(!unvisited.empty()) {
            node = unvisited.front();
            unvisited.pop_front();
            if(isSameTree(node, t)) {return true;}
            if(!node) {return false;}
            if(node->left) {unvisited.push_back(node->left);}
            if(node->right) {unvisited.push_back(node->right);}
        }
        return false;
    }
private:
    bool isSameTree(TreeNode *s, TreeNode *t) {
        if((!s)||(!t)) {
            return s == t ? true : false;
        }
        if(s->val != t->val) {
            return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
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
    BSTree tree, tree2;
    vector<int> input = {6,3,1,0,4,8,7};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    vector<int> input2 = {3,1,4};
    for(auto x : input2) {
        tree2.insert(x);
    }
    tree2.print();
    cout<<endl;
    Solution slt;
    cout<<slt.isSubtree(tree.root, tree2.root)<<endl;
    return 0;
}
