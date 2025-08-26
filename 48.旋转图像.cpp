/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer, last = n - 1 - layer;
            for (int offset = 0; offset < last - first; offset++) {
                int temp = matrix[first][first+offset];
                swap(matrix[first+offset][last], temp);
                swap(matrix[last][last-offset], temp);
                swap(matrix[last-offset][first], temp);
                swap(matrix[first][first+offset], temp);
            }
        }
    }
};
// @lc code=end

