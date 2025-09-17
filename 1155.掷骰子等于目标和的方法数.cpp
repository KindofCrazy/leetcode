/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1'000'000'007;

        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= target; t++) {
                for (int v = 1; v <= k && v <= t; v++) {
                    dp[i][t] = (dp[i][t] + dp[i-1][t-v]) % MOD;
                }
            }
        }

        return dp[n][target];
    }
};
// @lc code=end

