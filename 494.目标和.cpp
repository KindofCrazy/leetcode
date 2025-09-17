/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2 == 1) return 0;
        target /= 2;

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][target];
    }
};
// @lc code=end

