/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as
 the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the 
 most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer
*/

#include <iostream>
#include <algorithm>
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        map<int, int> frequence;
        if(!root) {
            return ret;
        }
        backIter(root, frequence);
        return getMostFrequent(frequence);
    }
private:
    int backIter(TreeNode *root, map<int, int> &frequence) {
        if(!root) {
            return 0;
        }
        int left_sum = backIter(root->left, frequence);
        int right_sum = backIter(root->right, frequence);
        int total = root->val + left_sum + right_sum;
        auto it = frequence.find(total);
        if(it != frequence.end()) {
            it->second += 1;
        }else {
            frequence[total] = 1;
        }
        return total;
    }
    vector<int> getMostFrequent(const map<int, int> &frequence) {
        vector<int> most_frequent;
        int max_freq = 0;
        for(auto it = frequence.begin(); it != frequence.end(); it++) {
            if(it->second > max_freq) {
                max_freq = it->second;
            }
        }
        for(auto it = frequence.begin(); it != frequence.end(); it++) {
            if(it->second == max_freq) {
                most_frequent.push_back(it->first);
            }
        }
        return most_frequent;
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
    vector<int> result = slt.findFrequentTreeSum(tree.root);
    cout<<result.size()<<endl;
    for(auto x : result) {
        cout << x << " ";
    }
    cout<<endl;
}
