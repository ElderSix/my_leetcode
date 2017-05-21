/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently
occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space
incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        if(!root) {
            return result;
        }
        //Two pass
        curr_cnt = 0;
        max_cnt = 0;
        curr_val = 0;
        travelForMaxCnt(root);
        cout<<max_cnt<<endl;
        curr_cnt = 0;
        curr_val = 0;
        travelForModes(root);
        return result;
    }
private:
    int curr_cnt;
    int max_cnt;
    int curr_val;
    vector<int> result;
    void travelForMaxCnt(TreeNode *root) {
        if(!root) {
            return;
        }
        travelForMaxCnt(root->left);
        getMaxCount(root->val);
        travelForMaxCnt(root->right);
    }
    void travelForModes(TreeNode *root) {
        if(!root) {
            return;
        }
        travelForModes(root->left);
        getModes(root->val);
        travelForModes(root->right);
    }
    void getMaxCount(int val) {
        if(val == curr_val) {
            curr_cnt++;
        }else {
            curr_cnt = 1;
            curr_val = val;
        }
        if(curr_cnt > max_cnt) {
            max_cnt = curr_cnt;
        }
    }
    void getModes(int val) {
        if(val == curr_val) {
            curr_cnt++;
        }else {
            curr_cnt = 1;
            curr_val = val;
        }
        if(curr_cnt == max_cnt) {
            result.push_back(val);
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
    vector<int> input = {1,2,2};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;

    Solution slt;
    vector<int> ret = slt.findMode(tree.root);
    for(auto x : ret) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
