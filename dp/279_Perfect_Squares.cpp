/*
Given a positive integer n, find the least number of perfect square numbers
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, INT_MAX - 1);
        v[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 1; i + j * j <= n; j++) {
                v[i + j * j] = std::min(v[i + j * j], v[i] + 1);
            }
        }
        return v[n];
    }
};

int main() {
    Solution slt;
    cout<<slt.numSquares(1)<<endl;
    cout<<slt.numSquares(7)<<endl;
    cout<<slt.numSquares(12)<<endl;
}
