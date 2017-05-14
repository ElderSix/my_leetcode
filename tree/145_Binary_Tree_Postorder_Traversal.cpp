/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        stack<TreeNode*> unvisited;
        TreeNode *last_visited = nullptr;
        TreeNode *node = root;
        unvisited.push(node);
        while(node && !unvisited.empty()) {
            if((node->left)&&(node->left != last_visited)) {
                //cout<<"unvisited push left: "<<node->val<<endl;
                unvisited.push(node);
                node = node->left;
            }else if(node->right){
                //cout<<"unvisited push right: "<<node->val<<endl;
                unvisited.push(node);
                node = node->right;
            }else {
                //cout<<"push "<<node->val<<endl;
                result.push_back(node->val);
                last_visited = node;
                while(unvisited.top()->right == node) {
                    node = unvisited.top();
                    //cout<<"inner push "<<node->val<<endl;
                    result.push_back(node->val);
                    last_visited = node;
                    unvisited.pop();
                }
                node = unvisited.top();
                unvisited.pop();
            }
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
    vector<int> input = {6,3,1,0,4,8,7};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    vector<int> ret = slt.postorderTraversal(tree.root);
    for(auto x : ret) {
        cout<<x<<",";
    }
    cout<<endl;
    return 0;
}
