/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            sums.push_back(sums[i] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    vector<int> sums;
};

void run_test(int ret, int exp){
    cout<<(ret == exp ? "Pass" : "Fail")<<": "<<ret<<" | "<<exp<<endl;
}

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    run_test(numArray.sumRange(0, 2), 1);
    run_test(numArray.sumRange(2, 5), -1);
    run_test(numArray.sumRange(0, 5), -3);
    run_test(numArray.sumRange(0, 0), -2);
    run_test(numArray.sumRange(5, 5), -1);

    return 0;
}