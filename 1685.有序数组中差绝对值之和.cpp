/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 */

// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int left = nums[i] * i - sum[i];
            int right = sum[n] - sum[i+1] - nums[i] * (n-1-i);
            res[i] = left + right;
        }

        return res;
    }
};
// @lc code=end

