/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
 */

// @lc code=start
class Solution {
public:
    int numSub(string s) {
        int n = s.size(), MOD = 1000'000'007, ans = 0;
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '1') {
                dp[i] = dp[i-1] + 1;
            }
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};
// @lc code=end

