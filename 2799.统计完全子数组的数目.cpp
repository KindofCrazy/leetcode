/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 *
 * [2799] 统计完全子数组的数目
 */

// @lc code=start
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> occ;
        for (int x: nums) {
            occ.insert(x);
        }
        int cap = occ.size();

        int ans = 0;
        unordered_map<int, int> mp;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && mp.size() < cap) {
                mp[nums[right++]]++;
            }

            if (mp.size() == cap) { 
                ans += (n - right + 1);
            }

            if (right > left) mp[nums[left]]--;
            if (mp[nums[left]] == 0) mp.erase(nums[left]);
        }

        return ans;
    }
};
// @lc code=end

