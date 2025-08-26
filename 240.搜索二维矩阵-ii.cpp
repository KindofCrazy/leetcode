/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int row = 0, col = cols - 1;
        while(row >= 0 && row < rows && col >= 0 && col < cols) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};
// @lc code=end

