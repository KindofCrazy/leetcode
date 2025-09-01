/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 *
 * [1930] 长度为 3 的不同回文子序列
 */

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> pre(26), suf(26), has(26);
        for (int i = 1; i < n; i++) {
            suf[s[i] - 'a']++;
        }

        for (int i = 1; i < n - 1; i++) {
            pre[s[i-1] - 'a']++;
            suf[s[i] - 'a']--;

            for (int j = 0; j < 26; j++) {
                if (pre[j] > 0 && suf[j] > 0) {
                    has[s[i] - 'a'] |= (1 << j);
                }
            }
        }

        int ans = 0;
        for (int mask: has) {
            ans += __builtin_popcount(mask);
        }

        return ans;
    }
};
// @lc code=end

