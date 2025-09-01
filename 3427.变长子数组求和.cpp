/*
 * @lc app=leetcode.cn id=3427 lang=cpp
 *
 * [3427] 变长子数组求和
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> sums(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            sums[i+1] = sums[i] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start = max(0, i - nums[i]);
            ans += (sums[i+1] - sums[start]);
        }

        return ans;
    }
};
// @lc code=end

