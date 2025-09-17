/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 *
 * [2684] 矩阵中移动的最大次数
 */

// @lc code=start
class Solution {
public:
    // unordered_map<int, int> mp;

    // int dfs(vector<vector<int>>& grid, int r, int c, int val) {
    //     if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] <= val) {
    //         return -1;
    //     }

    //     int key = r * grid[0].size() + c;
    //     if (mp.count(key)) return mp[key];

    //     int curVal = grid[r][c];
    //     int ret = 0;
    //     ret = max(ret, dfs(grid, r-1, c+1, curVal) + 1);
    //     ret = max(ret, dfs(grid, r,   c+1, curVal) + 1);
    //     ret = max(ret, dfs(grid, r+1, c+1, curVal) + 1);

    //     mp[key] = ret;
    //     return ret;
    // }

    // int maxMoves(vector<vector<int>>& grid) {
    //     int ans = 0;
    //     for (int i = 0; i < grid.size(); i++) {
    //         ans = max(ans, dfs(grid, i, 0, INT_MIN));
    //     }
        
    //     return ans;
    // }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dp[i][0] = true;
        }

        int ans = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                for (int k = max(0, i-1); k <= min(m-1, i+1); k++) {
                    dp[i][j] = dp[i][j] || (grid[i][j] > grid[k][j-1] && dp[k][j-1]);
                }
                if (dp[i][j]) ans = max(ans, j);
            }
        }

        return ans;
    }
};
// @lc code=end

