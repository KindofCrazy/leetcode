/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n ,vector<int>(n));

        for (int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++) {
            dp[row][0] = min(dp[row-1][0], dp[row-1][1]) + matrix[row][0];
            for (int col = 1; col < n - 1; col++) {
                dp[row][col] = min(dp[row-1][col-1], dp[row-1][col]);
                dp[row][col] = min(dp[row][col], dp[row-1][col+1]) + matrix[row][col];
            }
            dp[row][n-1] = min(dp[row-1][n-2], dp[row-1][n-1]) + matrix[row][n-1];
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
// @lc code=end

