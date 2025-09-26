/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, pre = 0;

        for (int n: nums) {
            pre = max(n, pre+n);
            ans = max(ans, pre);
        }

        return ans;
    }
};
// @lc code=end

