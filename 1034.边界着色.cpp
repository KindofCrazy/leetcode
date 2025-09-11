/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<int>>& ans, vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int color, int target) {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != target) {
            return true;
        }

        if (visited[row][col]) return false;
        visited[row][col] = true;
        
        bool down  = dfs(ans, grid, visited, row+1, col, color, target);
        bool up    = dfs(ans, grid, visited, row-1, col, color, target);
        bool right = dfs(ans, grid, visited, row, col+1, color, target);
        bool left  = dfs(ans, grid, visited, row, col-1, color, target);

        if (down || up || right || left) {
            ans[row][col] = color;
        }
        return false;

    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> ans = grid;

        dfs(ans, grid, visited, row, col, color, grid[row][col]);
        return ans;
    }
};
// @lc code=end

