/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = nums.size();
        int nums_len = nums.size();
        int max_len = 0;
        //Init with -1 not 0, because the first num may be 0 (e.g. [0,0,1]);
        vector<int> hash_tb(2 * nums_len + 1, -1);
        for(int i = 0; i < nums_len; i++) {
            sum += ((nums[i] == 0) ? -1 : 1);
            if(sum == nums_len) {
                //from [0] to [i]
                max_len = i + 1;
            }else {
                if(hash_tb[sum] != -1) {
                    max_len = std::max(max_len, i - hash_tb[sum]);
                }else {
                    hash_tb[sum] = i;
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution slt;

    vector<int> nums = {0,1,0};
    cout<<slt.findMaxLength(nums)<<endl;

    return 0;
}
