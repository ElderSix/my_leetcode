/*
Given an array of citations (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N
papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total
and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3
papers with at least 3 citations each and the remaining two with no more than 3 citations each,
his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int length = citations.size();
        if(length == 1) {
            return (citations[0] == 0) ? 0 : 1;
        }
        int h = length;
        for(int i = 1; i <= length; i++) {
            if(citations[length - i] < i) {
                h = i - 1;
                break;
            }
        }
        return h;
    }
};

int main() {
    vector<int> x = {0,0,1};
    Solution slt;
    std::cout<<slt.hIndex(x)<<std::endl;
    return 0;
}
