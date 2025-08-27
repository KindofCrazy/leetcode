/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> occ;

        int ans = 0, sum = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while (right < n && !occ.count(nums[right])) {
                sum += nums[right];
                occ.insert(nums[right++]);
            }

            ans = max(ans, sum);
            occ.erase(nums[left]);
            sum -= nums[left];
        }

        return ans;
    }
};
// @lc code=end

