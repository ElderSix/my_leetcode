/*
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 1       2        3           n/2
C      +C       +C    + ... +C      
 n-1     n-2      n-3         n/2

*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int climbStairs(int n) {
        int ret = 0;
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int prev = 2;
        int pprev = 1;
        for(int i = 2; i < n; i++){
            ret = (prev + pprev);
            pprev = prev;
            prev = ret;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout<<sol.climbStairs(45)<<endl;
    cout<<sol.climbStairs(50)<<endl;
    return 0;
}