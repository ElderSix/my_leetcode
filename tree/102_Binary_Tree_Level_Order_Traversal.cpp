/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) {
            return result;
        }
        deque<TreeNode*> visiting;
        TreeNode *temp;
        visiting.push_back(root);
        int count = 0;
        while(!visiting.empty()) {
            vector<int> row;
            //get count of visiting
            count = visiting.size();
            //loop for nodes in visiting, max count
            while(count > 0) {
                temp = visiting.front();
                row.push_back(temp->val);
                visiting.pop_front();
                if(temp->left) {visiting.push_back(temp->left);}
                if(temp->right) {visiting.push_back(temp->right);}
                count--;
            }
            result.push_back(row);
        }
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
    vector<vector<int>> ret = slt.levelOrder(tree.root);
    for(auto row : ret) {
        cout<<"[";
        for(auto x : row) {
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
