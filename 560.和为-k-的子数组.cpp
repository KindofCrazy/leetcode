 /*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefix = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        int ans = 0;
        for (int n: nums) {
            prefix += n;
            ans += mp[prefix-k];
            mp[prefix]++;
        }

        return ans;
    }
};
// @lc code=end

