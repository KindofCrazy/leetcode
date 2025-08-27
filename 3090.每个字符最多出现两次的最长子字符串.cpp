/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        int ans = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while(right < n && mp[s[right]] <= 1) {
                mp[s[right++]]++;
            }
            ans = max(ans, right - left);
            mp[s[left]]--;
        }

        return ans;
    }
};
// @lc code=end

