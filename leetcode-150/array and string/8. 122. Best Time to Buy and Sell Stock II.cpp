// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Prices are in day order. Buy and sell as many times as you want. Hold at most one share. Return the best profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: One Pass - Add every rise
// explanation:
/*
Every increase from yesterday to today can be taken as its own buy and sell.
A fall adds nothing.
The sum of those rises is the best profit, because a longer climb is the sum of its daily steps.
121 keeps only the single best sale. Here every rise is allowed.
*/
