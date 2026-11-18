// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Prices are in day order. Buy one day, sell a later day. Return the best profit, or 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = prices[0];
        int profit = 0;
        for (int price : prices) {
            cheapest = min(cheapest, price);
            profit = max(profit, price - cheapest);
        }
        return profit;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: One Pass - Cheapest price so far
// explanation:
/*
A sale on a day can only use a buy from that day or earlier.
cheapest is the lowest price seen up to today.
Today's profit is price - cheapest, and profit keeps the best of those.
Walking both ends skips pairs that are not symmetric, so [2, 4, 1] would return 0 instead of 2.
*/
