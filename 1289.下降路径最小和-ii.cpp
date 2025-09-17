/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0] = grid[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;

                    cost[i][j] = min(cost[i][j], cost[i-1][k] + grid[i][j]);
                }
            }
        }

        return ranges::min(cost.back());
    }
};
// @lc code=end

