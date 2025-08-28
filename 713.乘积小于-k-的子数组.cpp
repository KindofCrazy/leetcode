/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0, product = 1;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && product * nums[right] < k) {
                product *= nums[right++];
            }

            ans += (right - left);
            if (right > left) product /= nums[left];
        }

        return ans;
    }
};
// @lc code=end

