/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

        int top = 0, bottom = m-1;
        while (top <= bottom) {
            int mid = top + ((bottom - top) >> 1);

            if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else {
                top = mid + 1;
            }
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (matrix[bottom][mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left < n && matrix[bottom][left] == target;
    }
};
// @lc code=end

