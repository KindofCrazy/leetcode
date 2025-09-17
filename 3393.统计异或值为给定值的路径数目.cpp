/*
 * @lc app=leetcode.cn id=3393 lang=cpp
 *
 * [3393] 统计异或值为给定值的路径数目
 */

// @lc code=start
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int mx = 0;
        for (auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }
        int u = 1 << bit_width((unsigned) mx);
        if (k >= u) {
            return 0;
        }

        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(u)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 1; i < m; i++) {
            int val = grid[i][0];
            for (int x = 0; x < u; x++) {
                dp[i][0][x] = dp[i-1][0][x ^ val] % MOD;
            }
        }
        for (int j = 1; j < n; j++) {
            int val = grid[0][j];
            for (int x = 0; x < u; x++) {
                dp[0][j][x] = dp[0][j-1][x ^ val] % MOD;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int val = grid[i][j];
                for (int x = 0; x < u; x++) {
                    dp[i][j][x] = (dp[i-1][j][x ^ val] + dp[i][j-1][x ^ val]) % MOD;
                }
            }
        }

        return dp[m-1][n-1][k];
    }
};
// @lc code=end

