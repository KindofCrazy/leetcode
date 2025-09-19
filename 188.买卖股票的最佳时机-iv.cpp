/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        dp[0][0][0] = 0;
        dp[0][1][0] = INT_MIN;
        for (int t = 1; t <= k; t++) {
            dp[0][0][t] = 0;
            dp[0][1][t] = INT_MIN;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = max(dp[i-1][0][0]-prices[i-1], dp[i-1][1][0]);
        }

        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= k; t++) {
                dp[i][0][t] = max(dp[i-1][1][t-1] + prices[i-1], dp[i-1][0][t]);
                dp[i][1][t] = max(dp[i-1][0][t] - prices[i-1], dp[i-1][1][t]);
            }
        }

        return dp[n][0][k];
    }
};
// @lc code=end

