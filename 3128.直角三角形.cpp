/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 *
 * [3128] 直角三角形
 */

// @lc code=start
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> rowCount(rows), colCount(cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowCount[i] += grid[i][j];
                colCount[j] += grid[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    ans += (rowCount[i] - 1) * (colCount[j] - 1);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

