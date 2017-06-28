/*
Given a string, sort it in decreasing order based on the frequency of characters.
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Note that 'A' and 'a' are treated as two different characters.
*/
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    string frequencySort(string s) {
        //建立hash表：vector，下标为ascii，内容为相同字符组成的string
        vector<string> hash_map(128, "");

        for(int i = 0; i < s.size(); i++) {
            hash_map[int(s[i])] += s[i];
        }
        //对vector排序，排序依据为内容的长度
        std::sort(hash_map.begin(), hash_map.end(),
                [](string x, string y){return x.size() > y.size();});

        //将所有内容拼接成string
        string ret = "";
        for(auto sub_s : hash_map) {
            ret += sub_s;
        }
        return ret;
    }
};

int main() {
    string s = "tree";
    Solution slt;
    string ret = slt.frequencySort(s);
    cout<<ret<<endl;
    return 0;
}
