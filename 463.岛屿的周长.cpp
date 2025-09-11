/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 1;
        }

        if (visited[row][col]) return 0;
        visited[row][col] = true;
        int ret = 0;
        ret += dfs(grid, visited, row+1, col);
        ret += dfs(grid, visited, row-1, col);
        ret += dfs(grid, visited, row, col+1);
        ret += dfs(grid, visited, row, col-1);
        return ret;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, visited, i, j);
                }
            }
        }

        return 0;
    }
};
// @lc code=end

