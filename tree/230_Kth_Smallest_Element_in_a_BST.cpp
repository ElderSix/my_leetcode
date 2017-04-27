/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest
frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator(root);
        int ret = 0;
        for(int i = 0; i < k; i++) {
            if(hasNext()) {
                ret = next();
            }
        }
        return ret;
    }
private:
    void BSTIterator(TreeNode *root) {
        TreeNode *smallest = nullptr;
        if(!root) {
            return;
        }
        while(!root_to_smallest.empty()) {
            root_to_smallest.pop();
        }
        //Find the smallest
        smallest = root;
        while(smallest) {
            root_to_smallest.push(smallest);
            smallest = smallest->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !root_to_smallest.empty();
    }

    /** @return the next smallest number */
    int next() {
        //assert hasNext == true
        TreeNode *node = root_to_smallest.top();
        int ret = node->val;
        root_to_smallest.pop();
        if(node->right) {
            node = node->right;
            root_to_smallest.push(node);
            node = node->left;
            while(node) {
                root_to_smallest.push(node);
                node = node->left;
            }
        }
        return ret;
    }
    stack<TreeNode *> root_to_smallest;    //Include the smallest node
};

class BSTree {
public:
    BSTree():size(0),root(nullptr) {}
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
    vector<int> input = {6,5,4,3,2,1};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    cout << slt.kthSmallest(tree.root, 3) << " " << endl;
    cout << slt.kthSmallest(tree.root, 4) << " " << endl;
    return 0;
}
