/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> max_list;
        if(!root) {
            return max_list;
        }
        travel(root, 0, max_list);
        return max_list;
    }
private:
    //前序遍历，每次遍历当前节点时，检查是否更新当前层的最大值
    void travel(TreeNode *root, int level, vector<int> &max_list) {
        if((!root->left)&&(!root->right)) {
            updateMaxList(root, level, max_list);
            return;
        }
        updateMaxList(root, level, max_list);
        if(root->left) {
            travel(root->left, level+1, max_list);
        }
        if(root->right) {
            travel(root->right, level+1, max_list);
        }
    }
    void updateMaxList(TreeNode *root, int level, vector<int> &max_list) {
        if(max_list.size() > level) {
            max_list[level] = (max_list[level] > root->val) ? max_list[level] : root->val;
        }else {
            max_list.push_back(root->val);
        }
    }
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
    vector<int> input = {-3, -4, 3};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    vector<int> result = slt.largestValues(tree.root);
    for(auto x : result) {
        cout << x << " ";
    }
    cout<<endl;
}
