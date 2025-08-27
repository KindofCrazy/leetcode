/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int length = 0;
        long long total = accumulate(nums.begin(), nums.end(), 0), sum = 0, target = total - x;
        if (target == 0) return n;
        for (int left = 0, right = 0; right < n; left++) {
            right = max(left, right);
            while(right < n && sum + nums[right] <= target) {
                sum += nums[right++];
            }

            if (sum == target) {
                length = max(length, right - left);
            }

            if (right > left) sum -= nums[left];
        }

        return length == 0? -1: n - length;
    }
};
// @lc code=end

