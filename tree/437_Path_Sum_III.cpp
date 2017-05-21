/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/
#include <iostream>
#include <sstream>
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
    int pathSum(TreeNode* root, int sum) {
        vector<int> path_sum;
        if(!root) {
            return 0;
        }
        path_cnt = 0;
        target_sum = sum;
        travel(root, path_sum);
        return path_cnt;
    }
private:
    int target_sum;
    int path_cnt;
    void travel(TreeNode *root, vector<int> &path_sums) {
        if(!root) {
            return;
        }
        addValToPath(path_sums, root->val);
        refresh_cnt(path_sums);
        travel(root->left, path_sums);
        travel(root->right, path_sums);
        removeValFromPath(path_sums, root->val);
    }
    void addValToPath(vector<int> &path_sums, int val) {
        for(auto &x : path_sums) {
            x += val;
        }
        path_sums.push_back(val);
    }
    void removeValFromPath(vector<int> &path_sums, int val) {
        for(auto &x : path_sums) {
            x -= val;
        }
        path_sums.pop_back();
    }
    void refresh_cnt(vector<int> &path_sums) {
        for(auto x : path_sums) {
            if(x == target_sum) {
                path_cnt++;
            }
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
    vector<int> input = {10,5,7,3,2,1,12};
    for(auto x : input) {
        tree.insert(x);
    }
    tree.print();
    cout<<endl;

    Solution slt;
    cout<<slt.pathSum(tree.root, 22)<<endl;
    return 0;
}
