/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 *
 * [2684] 矩阵中移动的最大次数
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> mp;

    int dfs(vector<vector<int>>& grid, int r, int c, int val) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] <= val) {
            return -1;
        }

        int key = r * grid[0].size() + c;
        if (mp.count(key)) return mp[key];

        int curVal = grid[r][c];
        int ret = 0;
        ret = max(ret, dfs(grid, r-1, c+1, curVal) + 1);
        ret = max(ret, dfs(grid, r,   c+1, curVal) + 1);
        ret = max(ret, dfs(grid, r+1, c+1, curVal) + 1);

        mp[key] = ret;
        return ret;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, dfs(grid, i, 0, INT_MIN));
        }
        
        return ans;
    }
};
// @lc code=end

