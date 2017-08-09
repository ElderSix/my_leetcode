/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElementRecur(nums, 0, nums.size() - 1);
    }
private:
    int findPeakElementRecur(vector<int>& nums, int begin, int end) {
        int mid = begin + ((end - begin) >> 1);
        int left = (mid - 1 < 0) ? INT_MIN : nums[mid - 1];
        int right = (mid + 1 >= nums.size()) ? INT_MIN : nums[mid + 1];

        if((left <= nums[mid])&&(right <= nums[mid])) {
            return mid;
        }

        if((left <= nums[mid])&&(right >= nums[mid])) {
            return findPeakElementRecur(nums, mid + 1, end);
        }else {
            return findPeakElementRecur(nums, begin, mid);
        }
    }
};

int main() {
    vector<int> v = {1,3,2,1};
    Solution slt;
    cout<<slt.findPeakElement(v)<<endl;
    return 0;
}
