/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (int n: nums) {
            pre = max(n, pre+n);
            ans = max(ans, pre);
        }
        return ans;
    }
};
// @lc code=end

