/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
class Solution {
public:

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        dp[0] = 1;
        int mod = (int) pow(10, 9) + 7;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i-zero]) % mod;
            if (i >= one) dp[i] = (dp[i] + dp[i-one]) % mod;
        }

        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};
// @lc code=end

