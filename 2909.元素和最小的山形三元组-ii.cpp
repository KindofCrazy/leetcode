/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 *
 * [2909] 元素和最小的山形三元组 II
 */

// @lc code=start
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i+1], nums[i]);
        }

        int ans = INT_MAX, pre = nums[0];
        for (int j = 1; j < n - 1; j++) {
            if (nums[j] > pre && nums[j] > suf[j+1]) ans = min(ans, pre + nums[j] + suf[j+1]);
            pre = min(pre, nums[j]);
        }

        return ans == INT_MAX? -1: ans;
    }
};
// @lc code=end

