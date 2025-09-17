/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 *
 * [2304] 网格中的最小路径代价
 */

// @lc code=start
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n));
        cost[0] = grid[0];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = INT_MAX;
                for (int k = 0; k < n; k++) {
                    val = min(val, cost[i-1][k] + moveCost[grid[i-1][k]][j]);
                }
                cost[i][j] = grid[i][j] + val;
            }
        }

        return ranges::min(cost.back());
    }
};
// @lc code=end

