/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/
#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if((inorder.size() == 0)||(postorder.size() == 0)) {
            return nullptr;
        }
        int root_val = postorder[postorder.size() - 1];
        TreeNode *node = new TreeNode(root_val);
        vector<int>::iterator in_it = find(inorder.begin(), inorder.end(), root_val);
        vector<int> in_left(inorder.begin(), in_it);
        vector<int> in_right(in_it + 1, inorder.end());
        vector<int> post_left(postorder.begin(), postorder.begin() + in_left.size());
        vector<int> post_right(postorder.end() - 1 - in_right.size(), postorder.end() - 1);
        TreeNode *lchd = buildTree(in_left, post_left);
        TreeNode *rchd = buildTree(in_right, post_right);
        node->left = lchd;
        node->right = rchd;

        return node;
    }
    void printTree(TreeNode *root) {
        if(!root) {
            return;
        }
        cout<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    Solution slt;
    vector<int> inorder = {7,1,6,5,4,8,3};
    vector<int> postorder = {7,6,1,4,3,8,5};
    TreeNode *t = slt.buildTree(inorder, postorder);
    slt.printTree(t);
    return 0;
}
