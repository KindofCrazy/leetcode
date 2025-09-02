/*
 * @lc app=leetcode.cn id=3212 lang=cpp
 *
 * [3212] 统计 X 和 Y 频数相等的子矩阵数量
 */

// @lc code=start
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> xcnt(m+1, vector<int>(n+1, 0)), ycnt(m+1, vector<int>(n+1, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                xcnt[i+1][j+1] = xcnt[i+1][j] + xcnt[i][j+1] - xcnt[i][j] + (grid[i][j] == 'X');
                ycnt[i+1][j+1] = ycnt[i+1][j] + ycnt[i][j+1] - ycnt[i][j] + (grid[i][j] == 'Y');

                if (xcnt[i+1][j+1] == ycnt[i+1][j+1] && xcnt[i+1][j+1] > 0) {
                    ans++;
                }
            }
        }

        return ans;

    }
};
// @lc code=end

