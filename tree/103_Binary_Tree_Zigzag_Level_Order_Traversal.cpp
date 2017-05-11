/*
Given a binary tree, return the zigzag level order traversal of its nodes' values.
 (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) {
            return result;
        }
        bool l_to_r = false;
        TreeNode *temp;
        stack<TreeNode *> stack_l2r;
        stack<TreeNode *> stack_r2l;
        stack_l2r.push(root);
        result.push_back({root->val});
        while((!stack_r2l.empty())||(!stack_l2r.empty())) {
            if(!l_to_r) {
                vector<int> row;
                while(!stack_l2r.empty()) {
                    temp = stack_l2r.top();
                    stack_l2r.pop();
                    if(temp->right) {
                        row.push_back(temp->right->val);
                        stack_r2l.push(temp->right);
                    }
                    if(temp->left) {
                        row.push_back(temp->left->val);
                        stack_r2l.push(temp->left);
                    }
                }
                result.push_back(row);
                l_to_r = !l_to_r;
            }else {
                vector<int> row;
                while(!stack_r2l.empty()) {
                    temp = stack_r2l.top();
                    stack_r2l.pop();
                    if(temp->left) {
                        row.push_back(temp->left->val);
                        stack_l2r.push(temp->left);
                    }
                    if(temp->right) {
                        row.push_back(temp->right->val);
                        stack_l2r.push(temp->right);
                    }
                }
                result.push_back(row);
                l_to_r = !l_to_r;
            }
        }
        result.pop_back();
        return result;
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
    vector<vector<int>> ret = slt.zigzagLevelOrder(tree.root);
    for(auto row : ret) {
        cout<<"[";
        for(auto x : row) {
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
