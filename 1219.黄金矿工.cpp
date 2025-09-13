/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
public:

    vector<vector<bool>> visited;
    vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }

        visited[r][c] = true;
        int ret = 0;
        for (auto [dx, dy] : dir) {
            ret = max(ret, dfs(grid, r + dx, c + dy));
        }
        visited[r][c] = false;

        return ret + grid[r][c];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        visited.assign(grid.size(), vector<bool>(grid[0].size(), false));

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

