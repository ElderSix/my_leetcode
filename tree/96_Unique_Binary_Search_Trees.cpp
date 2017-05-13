/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        //catalan numbers
        vector<int> catalans;
        catalans.push_back(1);
        catalans.push_back(1);
        catalans.push_back(2);
        for(int x = 3; x <= n; x++) {
            int num = 0;
            int i, j;
            for(i = 0, j = x - 1; i <= x - 1; i++, j--) {
                num += catalans[i]*catalans[j];
            }
            catalans.push_back(num);
        }
        return catalans[n];
    }
};

int main() {
    Solution slt;
    cout<<slt.numTrees(15)<<endl;
}
