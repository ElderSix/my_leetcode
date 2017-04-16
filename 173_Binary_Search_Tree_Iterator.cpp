/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
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
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        smallest = nullptr;
        tree_root = root;
        root_to_smallest.erase(root_to_smallest.begin(), root_to_smallest.end());
        if(!root) {
            return;
        }
        //Find the smallest
        smallest = root;
        tree_root = root;
        while(smallest->left) {
            root_to_smallest.push_back(smallest);
            smallest = smallest->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return smallest != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        //assert hasNext == true
        int ret = smallest->val;
        getNextSmallest();
        return ret;
    }
private:
    void getNextSmallest() {
        TreeNode *tmp;
        if(smallest->right) {
            cout<<"right"<<endl;
            root_to_smallest.push_back(smallest);
            tmp = smallest->right;
            while(tmp->left) {
                root_to_smallest.push_back(tmp);
                tmp = tmp->left;
            }
            smallest = tmp;
        }else {
            if(smallest == tree_root) {
                smallest = nullptr;
                return;
            }
            vector<TreeNode *>::iterator it = root_to_smallest.end() - 1;
            cout<<"left"<<endl;
            if((*it)->left == smallest) {
                tmp = *it;
                root_to_smallest.erase(it);
                smallest = tmp;
            }else {
                tmp = *it;
                while(tmp != tree_root) {
                    root_to_smallest.erase(it);
                    it = root_to_smallest.end() - 1;
                    if(tmp == (*it)->left) {
                        tmp = *it;
                        root_to_smallest.erase(it);
                        smallest = tmp;
                        return;
                    }
                    tmp = *it;
                }
                root_to_smallest.erase(it);
                smallest = nullptr;
            }
        }
    }
    TreeNode *tree_root;
    TreeNode *smallest;
    vector<TreeNode *> root_to_smallest;    //Do not include the smallest node
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
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
    vector<int> input = {1,2,3,4,5,6};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;
    BSTIterator i = BSTIterator(tree.root);
    while (i.hasNext()) {
        cout << i.next() << " " << endl;
    }
}