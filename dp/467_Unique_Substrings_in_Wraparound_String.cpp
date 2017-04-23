/*
467. Unique Substrings in Wraparound String
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: 
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. 
In particular, your input is the string p and you need to output the number of different non-empty substrings of p 
in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
*/
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size() < 1) {
            return 0;
        }
        int sum = 1;    //At least 1 char
        int count = 1;
        int cont_begin = 0;
        int cont_end = 0;

        init_char_rec();

        for(int i = 1; i < p.size(); i++) {
            //规律：第一个字符计数为1，第二个字符计数+2，第三个字符计数+3，以此类推
            if(m_is_continue(p[i], p[i-1])) {
                count++;
                sum += count;
                cont_end = i;
            }else {
                //统计重复出现过的子字符串并从结果中减掉
                sum -= m_sum_already_in_cache(p, cont_begin, cont_end);
                //计数重新开始，当前字符为第一个
                count = 1;
                sum += count;
                cont_begin = cont_end = i;
            }
        }
        sum -= m_sum_already_in_cache(p, cont_begin, cont_end);
        //cout<<"Return with "<<sum<<endl;
        return sum;
    }
    void init_char_rec() {
        for(auto i = 'a'; i <= 'z'; i++) {
            m_char_rec[i] = 0;
        }
    }
    bool m_is_continue(char second, char first) {
        if((second - first + 26)%26 == 1) {
            return true;
        }
        return false;
    }
    int m_sum_already_in_cache(string p, int begin, int end) {
        int ret = 0;
        for(int i = begin; i <= end; i++) {
            if(m_char_rec[p[i]] <= (end - i + 1)) {
                //之前出现过的以这个字母开头的最长字符串，小于最新的以这个字母开头的最长字符串，更新cache
                ret += m_char_rec[p[i]];
                m_char_rec[p[i]] = end - i + 1;
            }
            else {
                //因为在进入函数前，已经按照当前最新的最长连续字符串累加过计数器了
                //当前最新的最长连续字符串长度比cache里保存的要短，因此要减掉这次累加的结果。
                //如前面出现过zab，这次是za，则需要减掉z,za，即减去2（当然还要减掉a，a会在下个循环里减掉）
                ret += end - i + 1;
            }
        }
        return ret;
    }
    std::map<char, int> m_char_rec; //26个元素的cache，保存以每个字符开头的最长连续字符串
};

int main() {
    Solution sol;
    //cout<<sol.canIWin(10, 11)<<endl;
    string p = "cac";
    cout<<sol.findSubstringInWraproundString(p)<<endl;
    return 0;
}