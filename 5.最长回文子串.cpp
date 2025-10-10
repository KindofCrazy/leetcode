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
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int ansBegin = 0, ansLen = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ansLen = 1;
        }
        for (int l = 2; l <= n; l++) {
            for (int begin = 0; begin < n; begin++) {
                int end = begin + l - 1;
                if (end >= n) {
                    break;
                }

                if (s[begin] != s[end]) {
                    dp[begin][end] = false;
                } else {
                    if (l == 2) {
                        dp[begin][end] = true;
                    } else {
                        dp[begin][end] = dp[begin+1][end-1];
                    }
                }

                if (dp[begin][end] && l > ansLen) {
                    ansBegin = begin;
                    ansLen = l;
                }
            }
        }

        return s.substr(ansBegin, ansLen);
    }
};
// @lc code=end

