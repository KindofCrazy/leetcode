/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int ans = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while (right < n && mp[nums[right]] + 1 <= k) {
                mp[nums[right++]]++;
            }
            
            ans = max(ans, right - left);
            mp[nums[left]]--;
        }

        return ans;
    }
};
// @lc code=end

