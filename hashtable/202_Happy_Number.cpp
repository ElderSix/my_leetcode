/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
replace the number by the sum of the squares of its digits, and repeat the process until the number
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
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
    bool isHappy(int n) {
        vector<int> sum_hash(1024, 0);
        int sum = get_next_sum(n);
        while((sum != 1)&&(sum_hash[sum] != 1)) {
            sum_hash[sum] = 1;
            sum = get_next_sum(sum);
        }
        if(sum == 1) {
            return true;
        }
        return false;
    }
private:
    int get_next_sum(int n) {
        int remain;
        int sum = 0;
        while(n > 0) {
            remain = n % 10;
            n = n / 10;
            sum += remain * remain;
        }
        return sum;
    }
};

int main() {
    Solution slt;
    for(int i = 0; i < 10; i++) {
        if(slt.isHappy(i)) {
            cout<<i<<endl;
        }
    }
}
