/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a
substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int l = s.size();
        if(l < 2) {
            return l;
        }

        int i = 0;
        int j = 1;
        int longest = 1;
        std::vector<int> char_hash(256, -1);
        char_hash[s[i]] = i;
        while(j < l) {
            if(char_hash[s[j]] >= 0) {
                if(j - i > longest) {
                    longest = j - i;
                }
                i = (i > char_hash[s[j]]) ? i : (char_hash[s[j]] + 1);
            }
            char_hash[s[j]] = j;
            j++;
        }

        return (j - i > longest) ? (j - i) : longest;
    }
};

int main() {
    std::string s = "abbba";
    Solution slt;
    cout<<slt.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
