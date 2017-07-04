/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
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
using std::map;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        map<int, vector<int>> key_freq_map;
        int count = 1;
        vector<int> count_array;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                count++;
            }else {
                key_freq_map[count].push_back(nums[i]);
                count = 1;
            }
        }
        key_freq_map[count].push_back(nums[nums.size() - 1]);
        for(auto it = key_freq_map.begin(); it != key_freq_map.end(); it++) {
            count_array.push_back(it->first);
        }

        std::sort(count_array.begin(), count_array.end());

        vector<int> result;
        for(int i = count_array.size() - 1; i >= 0; i--) {
            for(auto x : key_freq_map[count_array[i]]) {
                result.push_back(x);
                k--;
                if(k == 0) {
                    return result;
                }
            }
        }
        return result;
    }
};

template <typename T>
void printVector(vector<T> input) {
    for(auto x : input) {
        cout<<x<<", ";
    }
    cout<<endl;
}


int main() {
    vector<int> input = {1,1,1,2,2,2,3};
    Solution slt;
    printVector(slt.topKFrequent(input, 1));
    input = {1,1,2,2,3,3};
    printVector(slt.topKFrequent(input, 2));
}
