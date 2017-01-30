/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() < 1) {
            return 0;
        }
        findTarget(nums, S, nums.size() - 1);
        return total;
    }
    void findTarget(vector<int>& nums, int S, int idx) {
        if(idx == 0) {
            if(nums[idx] + S == 0)  {
                total++;
            }
            if(nums[idx] - S == 0) { 
                total++;
            }
            return;
        }
        findTarget(nums, S - nums[idx], idx - 1);
        findTarget(nums, S + nums[idx], idx - 1);
    }
private:
    int total;
};

int main() {
    Solution s;
    vector<int> x = {0,0,1};
    cout<<s.findTargetSumWays(x, 1)<<endl;
}