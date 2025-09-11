/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if (r < 0 || r >= grid1.size() || c < 0 || c >= grid1[0].size() || grid2[r][c] != 1) {
            return true;
        }

        grid2[r][c] = 0;
        bool ret = (grid1[r][c] == 1);

        bool up = dfs(grid1, grid2, r-1, c);
        bool down = dfs(grid1, grid2, r+1, c);
        bool left = dfs(grid1, grid2, r, c-1);
        bool right = dfs(grid1, grid2, r, c+1);
        if (up && down && left && right && ret) {
            return true;
        }

        return false;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    ans += dfs(grid1, grid2, i, j);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

