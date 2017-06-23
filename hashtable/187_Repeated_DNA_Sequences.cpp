/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> substr_count;
        for(int i = 0; i <= int(s.size() - 10); i++) {
            string substr = s.substr(i, 10);
            substr_count[substr] += 1;
        }
        vector<string> ret;
        for(auto it = substr_count.begin(); it != substr_count.end(); it++) {
            if(it->second > 1) {
                ret.push_back(it->first);
            }
        }
        return ret;
    }
};

int main() {
    string s = "AAAAAAAAAAA";
    Solution slt;
    vector<string> ret = slt.findRepeatedDnaSequences(s);
    for(auto x : ret) {
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;
}
