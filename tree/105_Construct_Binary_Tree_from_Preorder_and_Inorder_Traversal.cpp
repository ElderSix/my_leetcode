/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if((preorder.size() == 0)||(inorder.size() == 0)) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), root->val);
        vector<int> l_inorder(inorder.begin(), it);
        vector<int> l_preorder(preorder.begin() + 1, preorder.begin() + 1 + l_inorder.size());

        vector<int> r_inorder(it + 1, inorder.end());
        vector<int> r_preorder(preorder.end() - r_inorder.size(), preorder.end());

        TreeNode *l_chd = buildTree(l_preorder, l_inorder);
        TreeNode *r_chd = buildTree(r_preorder, r_inorder);
        root->left = l_chd;
        root->right = r_chd;

        return root;
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
    vector<int> inorder = {1,6,4,7,8,3,5};
    vector<int> preorder = {7,6,1,4,3,8,5};
    TreeNode *t = slt.buildTree(preorder, inorder);
    slt.printTree(t);
    return 0;
}
