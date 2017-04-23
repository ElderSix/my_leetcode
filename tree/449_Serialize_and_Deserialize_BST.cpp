/*
Serialization is the process of converting a data structure or object into a
sequence of bits so that it can be stored in a file or memory buffer, or
transmitted across a network connection link to be reconstructed later in the
same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is
no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary search tree can be serialized to a string
and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your
serialize and deserialize algorithms should be stateless.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::deque;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //BFS
        if(!root) {
            return "";
        }
        string ret;
        deque<TreeNode*> visiting;
        TreeNode *node;
        visiting.push_back(root);
        while(visiting.size() > 0) {
            node = visiting.front();
            visiting.pop_front();
            if(!node) {
                ret += " N";
                continue;
            }
            ret = ret + " " + std::to_string(node->val);
            visiting.push_back(node->left);
            visiting.push_back(node->right);
        }
        //strip last continuous "N"
        ret = ret.substr(0, ret.find_last_not_of(" N") + 1);
        //cout<<ret<<endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) {
            return nullptr;
        }

        //把所有节点值按顺序解析并放入vector
        std::stringstream ss;
        vector<string> val_vec;
        string::size_type pos = data.find_first_not_of(' ', 0);
        string::size_type tok_pos = data.find_first_of(' ', pos);
        string val_str = data.substr(pos, tok_pos - pos);
        val_vec.push_back(val_str);
        while(tok_pos != string::npos) {
            pos = data.find_first_not_of(' ', tok_pos);
            tok_pos = data.find_first_of(' ', pos);
            val_str = data.substr(pos, tok_pos - pos);
            val_vec.push_back(val_str);
        }
        int val;
        ss<<val_vec[0];
        ss>>val;
        TreeNode *root = new TreeNode(val);
        //按规则根据vector构造树
        //build_tree(root, 0, val_vec);
        build_tree_(root, val_vec);
        return root;
    }
private:
    void build_tree_(TreeNode *root, vector<string> &val_vec) {
        for(int i = 1; i < val_vec.size(); i++) {
            if(val_vec[i] != "N") {
                insert_node(root, str_to_int(val_vec[i]));
            }
        }
    }
    void insert_node(TreeNode *root, int val) {
        //cout<<val<<endl;
        TreeNode *node = new TreeNode(val);
        TreeNode *parent = root;
        while(parent) {
            if(parent->val >= val) {
                if(parent->left == nullptr) {
                    parent->left = node;
                    break;
                }
                parent = parent->left;
            }else {
                if(parent->right == nullptr) {
                    parent->right = node;
                    break;
                }
                parent = parent->right;
            }
        }
    }
    int str_to_int(string str) {
        std::stringstream ss;
        ss<<str;
        int ret;
        ss>>ret;
        return ret;
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

    Codec codec;
    tree.root = codec.deserialize(codec.serialize(tree.root));
    if(tree.root) {tree.print();};
    cout<<endl;
}
