/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */

// @lc code=start
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < hours.size(); i++) {
            ans += mp[(24 - hours[i] % 24) % 24];
            mp[hours[i] % 24]++;
        }

        return ans;
    }
};
// @lc code=end

