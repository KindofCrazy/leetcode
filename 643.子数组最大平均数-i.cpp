/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;

        for (int i = 0; i < k-1; i++) {
            sum += nums[i];
        }

        for (int left = 0, right = k-1; right < n; left++, right++) {
            sum += nums[right];
            maxSum = max(maxSum, sum);
            sum -= nums[left];
        }

        return (double) maxSum / k;
    }
};
// @lc code=end

