 /*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), prefix = 0;

        int ans = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            ans += mp.contains(prefix - k) ? mp[prefix - k]: 0;
            mp[prefix]++;
        }
        return ans;
    }
};
// @lc code=end

