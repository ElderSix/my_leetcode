/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.

Note:
N is a positive integer and will not exceed 15.
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int countArrangement(int N) {
        if(N <= 1) {
            return N;
        }
        vector<vector<int>> result;
        int pos = 1;
        for(int i = 1; i <= N; i++) {
            vector<int> tmp;
            tmp.push_back(i);
            countArrangementInner(N, tmp, pos + 1, &result);
        }
        return result.size();
    }
private:
    void countArrangementInner(int N, vector<int> selected, int pos, vector<vector<int>> *result) {
        for(int i = 1; i <= N; i++) {
            vector<int> sel(selected);
            if(((i % pos == 0) || (pos % i == 0)) && (!isSelected(i, sel))) {
                sel.push_back(i);
                if(sel.size() == N) {
                    for(int j = 0; j < N; j++) {
                        cout<<sel[j]<<" ";
                    }
                    cout<<endl;
                    result->push_back(sel);
                }else{
                    countArrangementInner(N, sel, pos + 1, result);
                }
            }
        }
    }
    bool isSelected(int x, vector<int> &selected) {
        for(auto k : selected) {
            if(x == k) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution slt;
    cout<<slt.countArrangement(15)<<endl; 
}