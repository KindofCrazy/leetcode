/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        
        vector<int> score(1e4+5, 0);
        for (int n: nums) {
            score[n] += n;
            maxVal = max(n, maxVal);
        }

        vector<int> dp(1e4+5, 0);
        int ans = 0;
        dp[1] = score[1];
        dp[2] = max(score[1], score[2]);
        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i-2]+score[i], dp[i-1]);
        }
        return dp[maxVal];
    }
};
// @lc code=end

