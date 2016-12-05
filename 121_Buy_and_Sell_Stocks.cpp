/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int min_so_far = prices[0];
        int max_profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - min_so_far > max_profit){
                max_profit = prices[i] - min_so_far;
            }
            min_so_far = (min_so_far > prices[i]) ? prices[i] : min_so_far;
        }
        return max_profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<solution.maxProfit(prices)<<endl;
    prices = {7, 6, 4, 3, 1};
    cout<<solution.maxProfit(prices)<<endl;
    prices = {1};
    cout<<solution.maxProfit(prices)<<endl;
    prices = {7, 8};
    cout<<solution.maxProfit(prices)<<endl;
    prices = {};
    cout<<solution.maxProfit(prices)<<endl;
}