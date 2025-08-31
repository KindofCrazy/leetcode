/*
 * @lc app=leetcode.cn id=2874 lang=cpp
 *
 * [2874] 有序三元组中的最大值 II
 */

// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int preMax = nums[0], maxDiff = 0;
        for (int k = 0; k < nums.size(); k++) {
            ans = max(ans, (long long) maxDiff * nums[k]);
            maxDiff = max(maxDiff, preMax - nums[k]);
            preMax = max(preMax, nums[k]);
        }

        return ans;
    }
};
// @lc code=end

