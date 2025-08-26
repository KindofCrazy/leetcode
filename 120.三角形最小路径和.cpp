/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        int layer = triangle.size();
        vector<int> first = {triangle[0][0]};
        dp.emplace_back(first);
        for (int i = 1; i < layer; i++) {
            vector<int> temp;
            temp.push_back(dp[i-1][0] + triangle[i][0]);
            for (int j = 1; j < i; j++) {
                temp.push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
            }
            temp.push_back(dp[i-1][i-1] + triangle[i][i]);
            dp.push_back(temp);
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
// @lc code=end

