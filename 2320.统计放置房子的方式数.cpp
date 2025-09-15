/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
class Solution {
public:
    int countHousePlacements(int n) {
        int mod = (int) pow(10, 9) + 7;
        vector<long long> dp(max(n, 2));
        dp[0] = 2;
        dp[1] = 3;

        for (int i = 2; i < n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }

        return dp[n-1] * dp[n-1] % mod;
    }
};
// @lc code=end

