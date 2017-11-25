#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nums_len = nums.size();
        int from = 0;
        int to = nums_len;
        int mid = (from + to) >> 1;

        int max_loop = nums_len;
        while(max_loop > 0) {
            int less = 0;
            int more = 0;
            int dup_count = 1;
            cout<<"Mid: "<<mid<<endl;
            for(int i = 0; i < nums_len; i++) {
                if(nums[i] < mid) {
                    less++;
                }else if (nums[i] > mid) {
                    more++;
                }else {
                    dup_count++;
                    if(dup_count > 2) {
                        cout<<"Found "<<nums[i]<<endl;
                        return mid;
                    }
                }
            }
            if(less > mid - 1) {
                to = mid;
            }else {
                from = mid;
            }
            mid = (from + to) >> 1;
            if(mid < 1) {
                return -1;
            }
            max_loop--;

        }
        return -1;
    }
};

int main() {
    Solution slt;
    vector<int> nums = {5,7,8,2,3,1,4,5,6};
    cout<<slt.findDuplicate(nums)<<endl;
    return 0;
}

