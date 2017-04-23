/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to
the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode *root) {
        if(!root) {
            return root;
        }
        getMaxNode(root);
        TreeNode *prev;
        int curr_val = 0;
        while(hasPrev()) {
            prev = getPrev();
            prev->val += curr_val;
            curr_val = prev->val;
        }
        return root;
    }
    TreeNode* convertBST2(TreeNode* root) {
        //Bad way
        if(!root) {
            return root;
        }
        tree_root = root;
        travelTree(root);
        return root;
    }
private:
    //方法1：先找到最大节点，然后往前逐个遍历前一个节点
    void getMaxNode(TreeNode *root) {
        pathToMax.push(root);
        TreeNode *curr = root->right;
        while(curr) {
            pathToMax.push(curr);
            curr = curr->right;
        }
    }
    TreeNode *getPrev() {
        TreeNode *curr = pathToMax.top();
        pathToMax.pop();
        TreeNode *ret = curr;
        if(curr->left) {
            curr = curr->left;
            getMaxNode(curr);
        }
        return ret;
    }
    bool hasPrev() {
        return pathToMax.size() != 0;
    }

    //方法2：中序遍历，先右子树，再左子树
    //对于每个节点，其值加上后继节点的值
    void travelTree(TreeNode* root) {
        if((!root->left)&&(!root->right)) {
            root->val += getValOfNext(root);
            return;
        }
        if(root->right) {
            travelTree(root->right);
        }
        root->val += getValOfNext(root);
        if(root->left) {
            travelTree(root->left);
        }
    }
    int getValOfNext(TreeNode* node) {
        TreeNode *curr;
        if(node->right) {
            curr = node->right;
            while(curr->left) {
                curr = curr->left;
            }
            return curr->val;
        }else {
            if(node == tree_root) {
                return 0;
            }
            stack<TreeNode *> path;
            curr = node;
            getPathToNode(path, tree_root, node);
            TreeNode *parent = path.top();
            path.pop();
            if(curr == parent->left) {
                return parent->val;
            }else {
                while((curr != parent->left) && (parent != tree_root)) {
                    curr = parent;
                    parent = path.top();
                    path.pop();
                }
                if(parent == tree_root) {
                    if(curr != parent->left) {
                        return 0;
                    }
                }
                return parent->val;
            }
        }
        return 0;
    }
    bool getPathToNode(stack<TreeNode*> &path, TreeNode* root, TreeNode* target) {
        if(root == target) {
            return true;
        }
        path.push(root);
        if(root->left) {
            if(getPathToNode(path, root->left, target)) {
                return true;
            }
        }
        if(root->right) {
            if(getPathToNode(path, root->right, target)) {
                return true;
            }
        }
        path.pop();
        return false;
    }
    TreeNode* tree_root;
    stack<TreeNode*> pathToMax;
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
    //vector<int> input = {10,6,20,3,7,11,21,22,23};
    //vector<int> input = {1,2,3,4,5,6};
    vector<int> input = {6,5,4,3,2,1};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    slt.convertBST(tree.root);
    tree.print();
    cout<<endl;
    return 0;
}
