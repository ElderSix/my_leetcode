/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other
elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant
space complexity?
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret = {0, 0};
        int idx = getDiffBit(nums);
        for(int i = 0; i < nums.size(); i++) {
            if(((nums[i] >> idx) & 0x1) == 0) {
                ret[0] ^= nums[i];
            }else {
                ret[1] ^= nums[i];
            }
        }
        return ret;
    }
private:
    int getDiffBit(vector<int>& nums) {
        for(int i = 0; i < 32; i++) {
            int x = 0;
            for(int j = 0; j < nums.size(); j++) {
                x ^= ((nums[j] >> i) & 0x1);
            }
            if(x != 0) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {1,2};
    Solution slt;
    vector<int> ret = slt.singleNumber(nums);
    cout<<ret[0]<<":"<<ret[1]<<endl;
    return 0;
}
