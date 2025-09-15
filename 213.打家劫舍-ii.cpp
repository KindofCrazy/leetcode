/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int robRange(vector<int>& nums, int l, int r) {
        int first = nums[l], second = max(nums[l], nums[l+1]);
        for (int i = l+2; i <= r; i++) {
            int tmp = max(first+nums[i], second);
            first = second;
            second = tmp;
        }

        return second;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
};
// @lc code=end

