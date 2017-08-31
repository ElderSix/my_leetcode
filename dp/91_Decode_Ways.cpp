/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
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
    int numDecodings(string s) {
        int n = s.size();
        if((n < 1)||(0 == std::stoi(string(s.begin(), s.begin() + 1)))) {
            return 0;
        }
        if(n == 1) {
            return (0 < std::stoi(s)) ? 1 : 0;
        }
        int pprev = 1;
        int prev = 1;
        for(int i = 1; i < n; i++) {
            int last_one = std::stoi(string(s.begin() + i, s.begin() + i + 1));
            int last_two = std::stoi(string(s.begin() + i - 1, s.begin() + i + 1));
            if(0 < last_one) {
                if((last_two >= 10)&&(last_two <= 26)) {
                    int tmp = prev;
                    prev = prev + pprev;
                    pprev = tmp;
                }else {
                    pprev = prev;
                }
            }else {
                //last_one == 0
                if((last_two >= 10)&&(last_two <= 26)) {
                    int tmp = prev;
                    prev = pprev;
                    pprev = tmp;
                }else {
                    return 0;
                }
            }
        }
        return prev;
    }
};

int main() {
    vector<string> sv = {"", "0", "12", "012", "102", "120","160"};
    Solution slt;
    for(auto s : sv) {
        cout<<slt.numDecodings(s)<<endl;
    }
    return 0;
}
