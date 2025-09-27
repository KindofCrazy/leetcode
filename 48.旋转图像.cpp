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
        for (int layer = 0; layer < n/2; layer++) {
            int top = layer, bottom = n-1-layer, left = layer, right = n-1-layer;
            for (int offset = 0; left+offset < right; offset++) {                
                swap(matrix[top][left+offset], matrix[right-offset][left]);
                swap(matrix[bottom-offset][left], matrix[bottom][right-offset]);
                swap(matrix[bottom][right-offset], matrix[top+offset][right]);
            }
        }
    }
};
// @lc code=end

