/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n+1));

        for (int i = 0; i < n; i++) {
            dp[i][1] = true;
            dp[i][0] = true;
        }

        int ansBegin = 0;
        int ansLen = 1;
        for (int len = 2; len <= n; len++) {
            for (int begin = 0; begin+len-1 < n; begin++) {
                if (s[begin] == s[begin+len-1] && dp[begin+1][len-2] == true) {
                    dp[begin][len] = true;
                    if (len > ansLen) {
                        ansBegin = begin;
                        ansLen = len;
                    }
                }
            }
        }

        return s.substr(ansBegin, ansLen);
    }
};
// @lc code=end

