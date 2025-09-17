/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for (int i = 1; i < m; i++) {
            triangle[i][0] = triangle[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
            }
            triangle[i][i] = triangle[i-1][i-1] + triangle[i][i];
        }

        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
// @lc code=end

