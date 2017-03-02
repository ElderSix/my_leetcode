/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if(!(n > 0 && k > 0 && n >= k)) {
            ret = {{}};
            return ret;
        }
        ret = do_combine(1, n, k);
        for(auto v : ret) {
            cout<<"[";
            for(auto x : v) {
                cout<<x<<" ";
            }
            cout<<"]"<<endl;
        }
        return ret;
    }

    vector<vector<int>> do_combine(int start, int n, int k) {
        vector<vector<int>> ret;
        int c;
        if(k == 1) {
            for(int i = start; i <= n; i++) {
                vector<int> s = {i};
                ret.push_back(s);
            }
            return ret;
        }
        for(int i = start; i <= n - k + 1; i++){
            vector<vector<int>> tmp_ret = do_combine(i + 1, n, k - 1);
            c = tmp_ret.size();
            while(c > 0) {
                tmp_ret[c - 1].push_back(i);
                ret.push_back(tmp_ret[c - 1]);
                c--;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    sol.combine(5, 0);
}