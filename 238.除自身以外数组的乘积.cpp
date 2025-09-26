/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), last(n), ans(n);
        pre[0] = 1;
        last[n-1] = 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            last[i] = last[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = pre[i] * last[i];
        }

        return ans;
    }
};
// @lc code=end

