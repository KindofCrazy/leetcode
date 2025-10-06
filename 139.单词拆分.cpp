/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.size();
        vector<bool> dp(slen+1);
        dp[0] = true;

        for (int i = 1; i <= slen; i++) {
            for (string word: wordDict) {
                if (i >= word.size() && s.substr(i-word.size(), word.size()) == word) {
                    dp[i] = dp[i] || dp[i-word.size()];
                }
            }
        }

        return dp[slen];
    }
};
// @lc code=end

