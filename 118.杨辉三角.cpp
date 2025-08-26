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
        for(int i = 0; i < numRows; i++) {
            vector<int> layer;
            layer.push_back(1);

            for (int j = 1; j < i; j++) {
                layer.push_back(ans.back()[j-1] + ans.back()[j]);
            }

            if (i > 0) layer.push_back(1);
            ans.emplace_back(layer);
        }

        return ans;
    }
};
// @lc code=end

