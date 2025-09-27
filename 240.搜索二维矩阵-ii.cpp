/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = 0, col = n-1;
        while (row >= 0 && row < m && col >= 0 && col < n) {
            int val = matrix[row][col];
            if (val == target) {
                return true;
            } else if (val > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};
// @lc code=end

