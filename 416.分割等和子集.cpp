/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        if (*max_element(nums.begin(), nums.end()) > target) return false;


        vector<vector<bool>> dp(n, vector<bool>(sum+1));
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[n-1][target];
    }
};
// @lc code=end

