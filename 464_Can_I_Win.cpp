/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. 
The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers of 1..15 
without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player 
to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false
*/
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    bool winCheck(int bitmap, int choosable, int desired) {
        int usedBitMap = bitmap;

        if(cache.find(usedBitMap) != cache.end()) {
            return cache[usedBitMap];
        }
        //choosable <= 20
        for(int i = 1; i < choosable + 1; i++) {
            usedBitMap &= bitmap;
            if((usedBitMap & (1 << i)) == 0){
                usedBitMap |= (1 << i);
                if((i >= desired) || !winCheck(usedBitMap, choosable, desired - i)) {
                    cache[usedBitMap] = false;
                    cache[bitmap] = true;
                    return true;
                }
            }
        }
        cache[bitmap] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) {
            return true;
        }
        if((maxChoosableInteger < 0) || (desiredTotal < 0)) {
            return false;
        }
        if(((1 + maxChoosableInteger) * maxChoosableInteger / 2) < desiredTotal ) {
            return false;
        }
        
        int usedBitMap = 0;
        return winCheck(usedBitMap, maxChoosableInteger, desiredTotal);
    }
    std::map<int, bool> cache;
};

int main() {
    Solution sol;
    //cout<<sol.canIWin(10, 11)<<endl;
    cout<<sol.canIWin(4, 6)<<endl;
    return 0;
}