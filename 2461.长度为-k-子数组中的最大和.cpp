/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        long long ans = 0, sum = 0;

        for (int i = 0; i < k-1; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }
        for (int left = 0, right = k-1; right < n; left++, right++) {
            mp[nums[right]]++;
            sum += nums[right];

            if (mp.size() == k) {
                ans = max(ans, sum);
            }

            mp[nums[left]]--;
            if (mp[nums[left]] == 0) {
                mp.erase(nums[left]);
            }
            sum -= nums[left];
        }

        return ans;
    }
};
// @lc code=end

