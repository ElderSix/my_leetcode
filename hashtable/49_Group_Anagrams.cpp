/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash_tb;
        string key;
        for(int i = 0; i < strs.size(); i++) {
            key = strs[i];
            sort(key.begin(), key.end());
            hash_tb[key].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto hash_iter = hash_tb.begin(); hash_iter != hash_tb.end(); hash_iter++) {
            ret.push_back(hash_iter->second);
        }
        return ret;
    }
};

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution slt;
    vector<vector<string>> result = slt.groupAnagrams(input);
    for(auto v : result) {
        cout<<"[";
        for(auto x : v) {
            cout<<x<<", ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
