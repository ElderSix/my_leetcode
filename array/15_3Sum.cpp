/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        while(i < n) {
            findSum(nums, i + 1, n - 1, result);
            i++;
            while((i < n)&&(nums[i] == nums[i - 1])) {
                i++;
            }
        }
        return result;
    }
private:
    void findSum(vector<int>& nums, int start, int end, vector<vector<int>>& result) {
        int target = nums[start - 1];
        while(start < end) {
            if(nums[start] + nums[end] == 0 - target) {
                result.push_back({target, nums[start], nums[end]});
                start++;
                end--;
                while((start < end)&&(nums[start - 1] == nums[start])) {
                    start++;
                }
                while((start < end)&&(nums[end + 1] == nums[end])) {
                    end--;
                }
            }else if(nums[start] + nums[end] < 0 - target) {
                start++;
            }else {
                end--;
            }
        }
    }
};

int main() {
    Solution slt;
    vector<int> nums = {-1,0,1,2,-1,2,-1,2,-4};
    vector<vector<int>> result = slt.threeSum(nums);
    cout<<"["<<endl;
    for(auto e : result) {
        cout<<"[";
        for(int x : e) {
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}
