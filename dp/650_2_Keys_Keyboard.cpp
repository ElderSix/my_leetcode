/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps
permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].
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

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) {
            return 0;
        }
        int d = maxDivisor(n);
        return minSteps(d) + n / d;
    }
    int maxDivisor(int x) {
        for(int i = 2; x / i >= i; i++) {
            if( x % i == 0) {
                return x / i;
            }
        }
        return 1;
    }
};

int main() {
    Solution slt;
    cout<<slt.minSteps(1)<<endl;
    cout<<slt.minSteps(12)<<endl;
    cout<<slt.minSteps(9)<<endl;

    return 0;
}
