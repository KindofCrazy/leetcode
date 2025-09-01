/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, INT_MIN);
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[j] > nums[k]) {
                    suf[j] = max(suf[j], nums[k]);
                }
            }
        }

        int preMin = nums[0];
        for (int j = 1; j < n - 1; j++) {
            if (preMin < suf[j]) {
                return true;
            }
            preMin = min(preMin, nums[j]);
        }

        return false;
    }
};
// @lc code=end

