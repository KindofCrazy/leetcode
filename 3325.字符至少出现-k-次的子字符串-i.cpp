/*
 * @lc app=leetcode.cn id=3325 lang=cpp
 *
 * [3325] 字符至少出现 K 次的子字符串 I
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();

        int ans = 0;
        unordered_map<char, int> mp;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && mp[s[right]] + 1 < k) {
                mp[s[right++]]++;
            }

            if (mp[s[right]] + 1 >= k) {
                ans += (n - right);
            }

            if (right > left) mp[s[left]]--;
        }

        return ans;
    }
};
// @lc code=end

