/*
 * @lc app=leetcode.cn id=1411 lang=cpp
 *
 * [1411] 给 N x 3 网格图涂色的方案数
 */

// @lc code=start
class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9 + 7;

        /* f0: ABC, f1: ABA */
        long long f0 = 6, f1 = 6;
        for (int i = 2; i <= n; i++) {
            long long new_f0 = (2 * f0 + 2 * f1) % MOD;
            long long new_f1 = (2 * f0 + 3 * f1) % MOD;

            f0 = new_f0;
            f1 = new_f1;
        }

        return (f0 + f1) % MOD;
    }
};
// @lc code=end

