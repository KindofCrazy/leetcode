/*
 * @lc app=leetcode.cn id=3264 lang=cpp
 *
 * [3264] K 次乘运算后的最终数组 I
 */

// @lc code=start
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            auto iter = min_element(nums.begin(), nums.end());
            *iter *= multiplier;
        }

        return nums;
    }
};
// @lc code=end

