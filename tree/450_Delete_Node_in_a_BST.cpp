/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //找到所需节点，O(log(n))
        std::pair<TreeNode *, TreeNode *> node_pair = findNode(root, key);
        TreeNode *parent = node_pair.first;
        TreeNode *node = node_pair.second;
        if(!node) {
            //没找到，直接返回原树根节点
            return root;
        }
        if((!node->left)&&(!node->right)) {
            if(!parent) {
                //根节点且没有子节点，删除后为空
                return nullptr;
            }
            //没有左右子树，直接删除即可
            updateParent(parent, node, nullptr);
            return root;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if(!left) {
            if(!parent) {
                //根节点且只有右子树，返回右节点
                return right;
            }
            updateParent(parent, node, right);
            return root;
        }
        if(!right) {
            if(!parent) {
                //根节点且只有左子树，返回左节点
                return left;
            }
            updateParent(parent, node, left);
            return root;
        }
        TreeNode *leftRight = left->right;
        //右旋，左节点的右子树挂到右节点下
        if(parent) {
            left->right = right;
            //BST插入，O(log(n))
            insert(right, leftRight);
            updateParent(parent, node, left);
        }else {
            left->right = right;
            insert(right, leftRight);
            //根节点为空，此时不能直接把root置为left，因为指针是值传递进来的
            return left;
        }
        return root;    //delete node?
    }
private:
    void updateParent(TreeNode *parent, TreeNode *org, TreeNode *dst) {
        if(parent->left == org) {
            parent->left = dst;
        }else {
            parent->right = dst;
        }
    }
    std::pair<TreeNode *, TreeNode *> findNode(TreeNode *root, int key) {
        TreeNode *parent = nullptr;
        TreeNode *node = root;
        while((node)&&(node->val != key)) {
            parent = node;
            node = (key <= node->val) ? node->left : node->right;
        }
        return std::make_pair(parent, node);
    }
    void insert(TreeNode *root, TreeNode *node) {
        if(!node) {
            return;
        }
        TreeNode *parent = root;
        while(1) {
            if(node->val <= parent->val) {
                if(!parent->left) {
                    parent->left = node;
                    return;
                }
                parent = parent->left;
            }else {
                if(!parent->right) {
                    parent->right = node;
                    return;
                }
                parent = parent->right;
            }
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
    vector<int> input = {5,3,2,4,6,7};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    Solution slt;
    tree.root = slt.deleteNode(tree.root, 6);
    if(tree.root) {tree.print();};
    cout<<endl;
}
