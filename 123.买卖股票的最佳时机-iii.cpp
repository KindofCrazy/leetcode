/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3)));
        for (int t = 0; t < 3; t++) {
            dp[0][0][t] = 0;
            dp[0][1][t] = INT_MIN;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0] - prices[i-1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= 2; t++) {
                dp[i][0][t] = max(dp[i-1][0][t], dp[i-1][1][t-1] + prices[i-1]);
                dp[i][1][t] = max(dp[i-1][1][t], dp[i-1][0][t] - prices[i-1]);
            }
        }
        return dp[n][0][2];
    }
};
// @lc code=end

