/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < 32; i++) {
            ret |= (getBitAtIdx(nums, i) << i);
        }
        return ret;
    }
private:
    int getBitAtIdx(vector<int>& nums, int idx) {
        int mask = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] >> idx) & mask;
        }
        return (sum % 3 == 1) ? 1 : 0;
    }
};

int main() {
    vector<int> nums = {123,123,7,7,7,11,66,11,66,123,256,11,66};
    Solution slt;
    cout<<slt.singleNumber(nums)<<endl;
    return 0;
}
