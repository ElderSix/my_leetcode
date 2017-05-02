/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes
inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        TreeNode *node = root;
        int count = 1;
        int left_height = 0;
        int right_height = 0;
        //calc height of sub-tree
        while(node->left) {
            left_height++;
            node = node->left;
        }
        node = root;
        while(node->right) {
            right_height++;
            node = node->right;
        }
        //if equal, return sub-tree node count
        if(left_height == right_height) {
            while(left_height > 0) {
                count += (1 << left_height);
                left_height--;
            }
            return count;
        }else {
            return count + countNodes(root->left) + countNodes(root->right);
        }
    }
private:
    vector<int> CountTable = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,
                            65536,131072,262144,524288,1048576,2097152};
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
    vector<int> input = {6,3,8};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    cout << slt.countNodes(tree.root) << " " << endl;
    return 0;
}
