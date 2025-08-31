/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */

// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++) {
            ans += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }

        return ans;
    }
};
// @lc code=end

