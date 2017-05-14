/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n == 0) {
            return result;
        }
        result = generateTreesInner(1, n);
        return result;
    }
    void printTree(TreeNode *root) {
        if(!root) {
            cout<<" null ";
            return;
        }
        cout<<"[";
        printTree(root->left);
        cout<<" "<<root->val<<" ";
        printTree(root->right);
        cout<<"]";
        return;
    }
private:
    vector<TreeNode*> generateTreesInner(int begin, int end) {
        vector<TreeNode*> result;
        if(begin > end) {
            result.push_back(nullptr);
            return result;
        }
        for(int i = begin; i <= end; i++) {
            vector<TreeNode*> left_trees = generateTreesInner(begin, i - 1);
            vector<TreeNode*> right_trees = generateTreesInner(i + 1, end);
            for(auto left : left_trees) {
                for(auto right : right_trees) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution slt;
    vector<TreeNode*> trees = slt.generateTrees(3);
    for(auto n : trees) {
        slt.printTree(n);
        cout<<endl;
    }
    cout<<endl;
}
