/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <iostream>
#include <vector>
#include <numeric>

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root) {
            return result;
        }
        vector<int> path;
        travel(root, sum, path, result);
        return result;
    }
private:
    void travel(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &path_list) {
        if((!root->left)&&(!root->right)) {
            if(std::accumulate(path.begin(), path.end(), 0) == sum - root->val) {
                path.push_back(root->val);
                path_list.push_back(path);
                path.pop_back();    //vector has pop back!
            }
            return;
        }
        path.push_back(root->val);
        if(root->left) {
            travel(root->left, sum, path, path_list);
        }
        if(root->right) {
            travel(root->right, sum, path, path_list);
        }
        path.pop_back();
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
    BSTree tree;
    vector<int> input = {6,3,1,0,4,8,9};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    vector<vector<int>> ret = slt.pathSum(tree.root, 13);
    for(auto row : ret) {
        for(auto x : row) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
