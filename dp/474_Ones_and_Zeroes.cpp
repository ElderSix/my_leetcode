/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings 
consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be 
used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::set;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i = 0; i < strs.size(); i++) {
            m_strs_map.push_back(count_zero_one(strs[i]));
        }
        
        return findMaxFormInner(strs, m, n);
    }
private:
    std::pair<int, int> count_zero_one(string &s) {
        int zero_count = 0;
        int one_count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0'){
                zero_count++;
            }else{
                one_count++;
            }
        }
        return std::make_pair(zero_count, one_count);
    }
    int findMaxFormInner(vector<string>& strs, int m, int n) {
        vector<vector<int>> result(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < strs.size(); i++) {
            for(int p = m; p >= m_strs_map[i].first; --p) {
                for(int q = n; q >= m_strs_map[i].second; --q) {
                    result[p][q] = std::max(result[p][q], 
                                    result[p - m_strs_map[i].first][q - m_strs_map[i].second] + 1);
                }
            }
        }
        
        return result[m][n];
    }
    vector<std::pair<int, int>> m_strs_map;
};

int main() {
    Solution sol;
    vector<string> str1 = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
    //vector<string> str2 = {"111001", "10", "0001", "1", "0"};
    cout<<sol.findMaxForm(str1, 8, 90)<<endl;
    return 0;
}





