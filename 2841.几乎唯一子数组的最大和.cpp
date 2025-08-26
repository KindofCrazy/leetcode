/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        long long sum = 0;
        for (int i = 0; i < k-1; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }

        long long ans = 0;
        for (int left = 0, right = k-1; right < n; left++, right++) {
            mp[nums[right]]++;
            sum += nums[right];
            
            if (mp.size() >= m) {
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

