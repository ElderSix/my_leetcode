/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

input: {1, 5, 2, 3, 9, 2}
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sums;
        if(nums.empty()){
            return 0;
        }
        auto len = nums.size();

        for(int i = 0; i < len; i++){
            switch(i){
                case 0:
                case 1:
                    sums.push_back(nums[i]);
                    break;
                case 2:
                    sums.push_back(nums[i] + sums[0]);
                    break;
                default:
                    sums.push_back(nums[i] + ((sums[i - 2] > sums[i - 3]) ? sums[i - 2] : sums[i - 3]));
                    break;
            }
        }
        if(len < 2){
            return sums[0]; 
        }
        return (sums[len - 1] > sums[len - 2]) ? sums[len - 1] : sums[len - 2];
    }
};

int main() {
    vector<int> nums = {1, 2, 9, 4, 1, 5, 2};
    Solution solution;
    cout<<solution.rob(nums)<<endl;
}

