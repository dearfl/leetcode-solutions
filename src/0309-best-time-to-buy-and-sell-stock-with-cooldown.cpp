// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.
//
// Find the maximum profit you can achieve. You may complete as many
// transactions as you like (i.e., buy one and sell one share of the stock
// multiple times) with the following restrictions:
//
// After you sell your stock, you cannot buy stock on the next day (i.e.,
// cooldown one day).
// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).
//
//

// my naive solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], dp[j - 2] + max(prices[i] - prices[j], 0));
            }
            dp[i] = max(dp[i], dp[i-1]);
            res = max(res, dp[i]);
        } 
        return res;
    }
};

// o(n) solution by npvinhphat (State Machine Thinking)
class Solution {
public:
    int maxProfit(vector<int>& prices){
        if (prices.size() <= 1) return 0;
        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);
        s1[0] = -prices[0];
        s0[0] = 0;
        s2[0] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[prices.size() - 1], s2[prices.size() - 1]);
    }
};
