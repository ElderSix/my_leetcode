/*
Given an array of n positive integers and a positive integer s, find the minimal length of a 
contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead. 
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. 
*/
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int least_len = nums.size() + 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= s) {
                least_len = 1;
                break;
            }
            for(; start < nums.size(); start++) {
                sum += nums[start];
                if(sum >= s) {
                    least_len = (start - i + 1 < least_len) ? (start - i + 1) : least_len;
                    //cout<<"Find len : "<<least_len<<", start:"<<start<<", i:"<<i<<endl;
                    sum = sum - nums[i] - nums[start];
                    break;
                }
            }
            if(start >= nums.size()) {
                break;
            }
        }
        return least_len > nums.size() ? 0 : least_len;
    }
};

int main() {
    vector<int> nums = {1,1,1,1,1,1,1};
    Solution slt;
    cout<<slt.minSubArrayLen(7, nums)<<endl;
    getchar();
    return 0;
}