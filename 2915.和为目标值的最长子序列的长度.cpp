/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 *
 * [2915] 和为目标值的最长子序列的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(target+1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= target; t++) {
                dp[i][t] = dp[i-1][t];
                if (t >= nums[i-1]) {
                    dp[i][t] = max(dp[i][t], dp[i-1][t-nums[i-1]] + 1);
                }
            }
        }

        return dp[n][target] > 0? dp[n][target]: -1;
    }
};
// @lc code=end

