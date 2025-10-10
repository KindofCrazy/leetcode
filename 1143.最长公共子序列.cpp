/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        
        for (int i = 0; i < l1; i++) {
            if (text1[i] == text2[0] || (i > 0 && dp[i-1][0] == 1)) {
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < l2; j++) {
            if (text1[0] == text2[j] || (j > 0 && dp[0][j-1] == 1)) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < l1; i++) {
            for (int j = 1; j < l2; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[i] == text2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }

        return dp[l1-1][l2-1];
    }
};
// @lc code=end

