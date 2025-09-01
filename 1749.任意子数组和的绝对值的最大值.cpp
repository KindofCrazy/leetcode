/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1), prefixMinSum(n+1, INT_MAX), prefixMaxSum(n+1, INT_MIN);
        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int ans = *max_element(prefixSum.begin(), prefixSum.end()) - *min_element(prefixSum.begin(), prefixSum.end());
        return ans;
    }
};
// @lc code=end

