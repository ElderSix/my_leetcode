/*
Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4) {
            return ret;
        }
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if((i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) {
                continue;
            }

            for(int j = i + 1; j < n - 2; j++) {
                if((j > i+1) && (nums[j] == nums[j-1])) {
                    continue;
                }
                if(nums[i] + nums[n-1] + nums[n-2] + nums[j] < target) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    if(nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                        continue;
                    }
                    if(nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                        continue;
                    }
                    ret.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while((left < right)&&(nums[left+1] == nums[left])) {
                        left++;
                    }
                    while((left < right)&&(nums[right-1] == nums[right])) {
                        right--;
                    }
                    left++;
                }
            }
        }
        return ret;
    }
};

int main() {
    //vector<int> S = {-493,-470,-464,-453,-451,-446,-445,-407,-406,-393,-328,-312,-307,-303,-259,-253,-252,-243,-221,-193,-126,-126,-122,-117,-106,-105,-101,-71,-20,-12,3,4,20,20,54,84,98,111,148,149,152,171,175,176,211,218,227,331,352,389,410,420,448,485};
    vector<int> S = {0,-3,-2,-1,3,2,1};
    int target = 0; //1057
    Solution sol;
    vector<vector<int>> ret = sol.fourSum(S, target);
    cout<<"["<<endl;
    for(auto v : ret) {
        for(auto x : v) {
            cout<<x<<", ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}
