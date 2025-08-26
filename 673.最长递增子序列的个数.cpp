/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int len = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i] ) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j]+1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
                len = max(dp[i], len);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == len) ans += count[i];
        }
        return ans;
    }
};
// @lc code=end

