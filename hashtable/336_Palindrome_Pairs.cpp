/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that
the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        std::unordered_map<string, int> words_map;
        for(int i = 0; i < words.size(); i++) {
            words_map[reverse_word(words[i])] = i;
        }

        for(int i = 0; i < words.size(); i++) {
            if(words[i].size() == 0) {
                //this is for ""
                for(auto it = words_map.begin(); it != words_map.end(); it++) {
                    if(is_palindrome(it->first) && (it->second != i)) {
                        result.push_back({i, it->second});
                    }
                }
                continue;
            }
            for(int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if(check_result(left, right, words_map, i)) {
                    result.push_back({i, words_map[left]});
                }

                if(check_result(right, left, words_map, i)) {
                    result.push_back({words_map[right], i});
                }
            }
        }
        return result;
    }
private:
    string reverse_word(string& word) {
        string ret = "";
        for(auto it = word.rbegin(); it != word.rend(); it++) {
            ret += *it;
        }
        return ret;
    }
    bool is_in_map(string& word, std::unordered_map<string, int>& words_map) {
        return (words_map.find(word) != words_map.end());
    }
    bool is_palindrome(const string& word) {
        int idx, ridx;
        for(idx = 0, ridx = word.size() - 1; idx < ridx; idx++, ridx--) {
            if(word[idx] != word[ridx]) {
                return false;
            }
        }
        return true;
    }
    bool check_result(string& left, string& right, std::unordered_map<string, int>& words_map, int idx){
        return ((is_in_map(left, words_map))&&(is_palindrome(right))&&(words_map[left] != idx));
    }
};

int main() {
    vector<string> input = {"abcd","dcba","lls","s","ssll"};
    //vector<string> input = {"a", "" };
    Solution slt;
    vector<vector<int>> ret = slt.palindromePairs(input);
    for(auto x : ret) {
        cout<<"[";
        for(auto y : x) {
            cout<<y<<", ";
        }
        cout<<"],";
    }
    cout<<endl;
}
