/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows - 1;

        if (matrix[0][0] > target || matrix[rows-1][cols-1] < target)  {
            return false;
        }
        while(left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] < target) {
                left = mid + 1;
            } else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        int row = left - 1;
        if (row < 0) return false;
        left = 0, right = cols - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] < target) {
                left = mid + 1;
            } else if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

