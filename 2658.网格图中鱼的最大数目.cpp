/*
 * @lc app=leetcode.cn id=2658 lang=cpp
 *
 * [2658] 网格图中鱼的最大数目
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        int ret = grid[r][c];
        grid[r][c] = 0;
        ret += dfs(grid, r+1, c);
        ret += dfs(grid, r-1, c);
        ret += dfs(grid, r, c+1);
        ret += dfs(grid, r, c-1);
        return ret;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
// @lc code=end

