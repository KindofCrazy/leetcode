/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
public:

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        }

        if (grid[r][c] == 1) return true;
        grid[r][c] = 1;

        bool up = dfs(grid, r-1, c);
        bool down = dfs(grid, r+1, c);
        bool left = dfs(grid, r, c-1);
        bool right = dfs(grid, r, c+1);
        if (up && down && left && right) {
            return true;
        }

        return false;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    ans += dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

