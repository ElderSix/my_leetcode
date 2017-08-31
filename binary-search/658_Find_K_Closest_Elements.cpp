/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be 
sorted in ascending order. If there is a tie, the smaller elements are always preferred. 
Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = binary_search(arr, x);
        return get_knn(arr, k, x, pos);
    }
private:
    int binary_search(vector<int>& arr, int x) {
        int p, q, m;
        p = 0;
        q = arr.size() - 1;
        while(p <= q) {
            m = p + (q - p) / 2;
            if(arr[m] == x) {
                return m;
            }
            if(arr[m] > x) {
                q = m - 1;
            }else {
                p = m + 1;
            }
        }
        return q;
    }
    vector<int> get_knn(vector<int>&arr, int k, int x, int x_pos) {
        vector<int> result;
        if(x_pos == -1) {
            for(int i = 0; i < k; i++) {
                result.push_back(arr[i]);
            }
            return result;
        }
        if(x_pos == arr.size() - 1) {
            for(int i = k; i > 0; i--) {
                result.push_back(arr[x_pos - i + 1]);
            }
            return result;
        }
        int left, right, len;
        left = x_pos;
        right = x_pos + 1;
        len = k;
        while(k > 0) {
            if(x - arr[left] <= arr[right] - x) {
                result.push_back(arr[left]);
                left--;
                if(left < 0) {
                    int res = len - result.size();
                    for(int i = right; i < right + res ; i++) {
                        result.push_back(arr[i]);
                    }
                    break;
                }                
            }else {
                result.push_back(arr[right]);
                right++;
                if(right > arr.size() - 1) {
                    int res = len - result.size();
                    for(int i = left; i > left - res; i--) {
                        result.push_back(arr[i]);
                    }
                    break;
                }
            }
            k--;
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> v = {0,1,1,1,2,3,6,7,8,9};
    Solution slt;
    cout<<"Start"<<endl;
    
    vector<int> o = slt.findClosestElements(v, 9, 4);
    for(auto x : o) {
        cout<<x<<" ";
    }
    cout<<endl;
    
    o = slt.findClosestElements(v, 4, 11);
    for(auto x : o) {
        cout<<x<<" ";
    }
    cout<<endl;
    
    o = slt.findClosestElements(v, 3, -110);
    for(auto x : o) {
        cout<<x<<" ";
    }
    cout<<endl;
    
    getchar();
    return 0;
}