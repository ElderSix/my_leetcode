/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets 
such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

*/
#include <iostream>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int sum_part = sum / 2;
        vector<int> d(sum_part + 1, 0);

        for(int i = 1; i <= nums.size(); i++){
            for(int j = sum_part; j >= nums[i-1]; j--) {
                d[j] = std::max(d[j], d[j - nums[i - 1]] + nums[i - 1]);
            }
        }
        int ret = 0;
        for(auto x : d) {
            if(x > ret) {
                ret = x;
            }
            //cout<<x<<" ";
        }
        //cout<<endl;
        return ret == sum_part;
    }
};

int main() {
    Solution s;
    vector<int> x = {2};
    cout<<s.canPartition(x)<<endl;
}
