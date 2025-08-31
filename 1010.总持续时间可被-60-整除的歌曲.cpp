/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < time.size(); i++) {
            ans += mp[(60 - time[i] % 60) % 60];
            mp[time[i] % 60]++;
        }

        return ans;
    }
};
// @lc code=end

