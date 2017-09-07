/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int uniquePaths(int m, int n) {
        cache = vector<vector<int>>(m, vector<int>(n, 0));
        return uniquePathsRecurr(m - 1, n - 1);
    }
    int uniquePathsRecurr(int m, int n) {
        if((m == 0)||(n == 0)) {
            cache[m][n] = 1;
        }else if(cache[m][n] == 0) {
            for(int i = 0; i <= n; i++) {
                cache[m][n] += uniquePathsRecurr(m - 1, n - i);
            }
        }
        return cache[m][n];
    }
private:
    vector<vector<int>> cache;
};

int main() {
    Solution slt;
    cout<<slt.uniquePaths(99,99)<<endl;
    return 0;
}
