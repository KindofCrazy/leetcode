/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 *
 * [2874] 有序三元组中的最大值 II
 */

// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i+1], nums[i]);
        }

        long long ans = 0;
        int preMax = nums[0];
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, (long long) (preMax - nums[j]) * suf[j+1]);
            preMax = max(preMax, nums[j]);
        }

        return ans;
    }
};
// @lc code=end

