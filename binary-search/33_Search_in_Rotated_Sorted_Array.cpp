/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
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
    int search(vector<int>& nums, int target) {
        return recur_search(nums, 0, nums.size() - 1, target);
    }
private:
    int binary_search(vector<int>& nums, int begin, int end, int target) {
        if(begin > end) {
            return -1;
        }
        int m = begin + ((end - begin) >> 1);
        if(nums[m] == target) {
            return m;
        }
        if(nums[m] < target) {
            return binary_search(nums, m + 1, end, target);
        }else {
            return binary_search(nums, begin, m - 1, target);
        }
    }
    int recur_search(vector<int>& nums, int begin, int end, int target) {
        if(begin > end) {
            return -1;
        }
        int m = begin + ((end - begin) >> 1);
        if(nums[m] == target) {
            return m;
        }
        if(nums[m] < target) {
            if(nums[end] >= nums[m]) {
                if(nums[end] < target) {
                    return recur_search(nums, begin, m - 1, target);
                }else {
                    return binary_search(nums, m + 1, end, target);
                }
            }else {
                return recur_search(nums, m + 1, end, target);
            }
        }else {
            if(nums[begin] <= nums[m]) {
                if(nums[begin] > target) {
                    return recur_search(nums, m + 1, end, target);
                }else {
                    return binary_search(nums, begin, m - 1, target);
                }
            }else {
                return recur_search(nums, begin, m - 1, target);
            }
        }
    }
};

int main() {
    vector<int> x = {17, 18, 0, 1, 3, 4, 15, 16};
    Solution slt;
    cout<<slt.search(x, 6)<<endl;
    cout<<slt.search(x, 8)<<endl;
    cout<<slt.search(x, 15)<<endl;
    cout<<slt.search(x, 18)<<endl;
    cout<<slt.search(x, 1)<<endl;
    cout<<slt.search(x, 3)<<endl;
    cout<<slt.search(x, 17)<<endl;
    cout<<slt.search(x, 4)<<endl;
    cout<<slt.search(x, 0)<<endl;
    cout<<"==========="<<endl;
    x = {3,1};
    cout<<slt.search(x, 3)<<endl;
    cout<<slt.search(x, 1)<<endl;
    cout<<slt.search(x, 2)<<endl;
    cout<<"==========="<<endl;
    x = {1,3};
    cout<<slt.search(x, 3)<<endl;
    cout<<slt.search(x, 1)<<endl;
    cout<<slt.search(x, 2)<<endl;
    cout<<"==========="<<endl;
    getchar();
    return 0;
}