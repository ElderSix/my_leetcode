/*
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::pair;
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
    int diameterOfBinaryTree(TreeNode* root) {
        //bfs
        //for each node, calc deepest left leaf and deepest right leaf, then calc the sum
        //get the bigist
        if(!root) {
            return 0;
        }
        int diameter = 0;
        deque<TreeNode*> visiting;
        visiting.push_back(root);
        TreeNode *node;
        while(!visiting.empty()) {
            node = visiting.front();
            visiting.pop_front();
            int d = getDiameterOfNode(node);
            diameter = (d > diameter) ? d : diameter;
            if(node->left) {
                visiting.push_back(node->left);
            }
            if(node->right) {
                visiting.push_back(node->right);
            }
        }
        return diameter;
    }
private:
    int getDiameterOfNode(TreeNode *root) {
        int left = 0;
        int right = 0;
        dfs(root->left, 1, left);
        dfs(root->right, 1, right);
        return left + right;
    }
    void dfs(TreeNode *root, int depth, int &deepest) {
        if(!root) {
            return;
        }
        deepest = (depth > deepest) ? depth : deepest;
        if(root->left) {
            dfs(root->left, depth + 1, deepest);
        }
        if(root->right) {
            dfs(root->right, depth + 1, deepest);
        }
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {
    BSTree tree;

    vector<int> input = {10,5,2,1,7,8};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;

    Solution slt;
    cout<<slt.diameterOfBinaryTree(tree.root)<<endl;
    return 0;
}
