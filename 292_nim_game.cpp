/*
You are playing the following Nim Game with your friend: There is a heap of stones on the table, 
each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will 
be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine 
whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, 
or 3 stones you remove, the last stone will always be removed by your friend.
*/
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

class Solution {
public:
    bool canWinNim(int n) {
        //map<int, bool> cache;
        //return canWinNimInner(n, cache);
        return (n % 4 == 0) ? false : true;
    }
    bool canWinNimInner(int n, map<int, bool> &cache) {
        map<int, bool>::iterator it;
        if((n <= 3)&&(n > 0)) {
            //cache[n] = true;
            return true;
        }
        if(n <= 0) {
            return false;
        }
        it = cache.find(n);
        if(it != cache.end()) {
            return it->second;
        }

        cache[n] = (!canWinNimInner(n - 1, cache)) || (!canWinNimInner(n - 2, cache)) 
                    || (!canWinNimInner(n - 3, cache));
        return cache[n];
    }   
};

int main() {
    Solution slt;
    cout<<slt.canWinNim(8)<<endl;
    cout<<slt.canWinNim(20)<<endl;
    cout<<slt.canWinNim(40)<<endl;
    cout<<slt.canWinNim(60)<<endl;
    cout<<slt.canWinNim(80)<<endl;
    cout<<slt.canWinNim(100)<<endl;
    cout<<slt.canWinNim(120)<<endl;
}