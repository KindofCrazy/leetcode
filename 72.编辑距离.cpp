/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1));

        for (int i = 1; i <= l1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= l2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return dp[l1][l2];
    }
};
// @lc code=end

