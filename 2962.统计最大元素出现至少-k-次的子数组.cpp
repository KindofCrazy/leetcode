/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());

        long long ans = 0, maxCount = 0;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && maxCount < k) {
                maxCount += (nums[right++] == maxNum);
            }

            if (maxCount >= k) {
                ans += (n - right + 1);
            }

            maxCount -= (nums[left] == maxNum);
        }

        return ans;
    }
};
// @lc code=end

