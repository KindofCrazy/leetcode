/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> layer(i+1);
            layer[0] = 1;
            for (int j = 1; j < i; j++) {
                layer[j] = ans.back()[j-1] + ans.back()[j];
            }
            layer[i] = 1;

            ans.emplace_back(layer);
        }

        return ans;
    }
};
// @lc code=end

