/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 *
 * [2588] 统计美丽子数组数目
 */

// @lc code=start
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> mp{{0, 1}};
        int s = 0;
        for (int n: nums) {
            s ^= n;
            ans += mp[s];
            mp[s]++;
        }

        return ans;
    }
};
// @lc code=end

