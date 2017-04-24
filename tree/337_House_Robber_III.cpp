/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area,
called the "root." Besides the root, each house has one and only one parent house. After a tour,
the smart thief realized that "all houses in this place forms a binary tree". It will automatically
contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

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
    int rob(TreeNode* root) {
        int ret = 0;
        ret = std::max(rob_tree(root, true), rob_tree(root, false));
        return ret;
    }
private:
    int rob_tree(TreeNode* root, bool rob_root) {
        if(!root) {
            return 0;
        }
        if((!root->left)&&(!root->right)) {
            return rob_root ? root->val : 0;
        }
        std::pair<TreeNode*, bool> cache_key = std::make_pair(root, rob_root);
        if(cache.find(cache_key) != cache.end()) {
            return cache[cache_key];
        }
        if(rob_root) {
            cache[cache_key] = root->val + rob_tree(root->left, false) + rob_tree(root->right, false);
        }else {
            cache[cache_key] = std::max(std::max(
                rob_tree(root->left, true) + rob_tree(root->right, true),
                rob_tree(root->left, true) + rob_tree(root->right, false)),
                std::max(rob_tree(root->left, false) + rob_tree(root->right, true),
                rob_tree(root->left, false) + rob_tree(root->right, false))
            );
        }
        return cache[cache_key];
    }
    map<std::pair<TreeNode*, bool>, int> cache;
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

    vector<int> input = {41,37,44,24,39,42,48,1,35,38,40,43,46,49,0,2,30,36,45,47,4,29,32,3,9,26,
                        31,34,7,11,25,27,33,6,8,10,16,28,5,15,19,12,18,20,13,17,22,14,21,23};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    cout<<endl;

    Solution slt;
    cout<<slt.rob(tree.root)<<endl;
}
