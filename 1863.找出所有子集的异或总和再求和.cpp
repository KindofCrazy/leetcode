/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
class Solution {
public:

    int ans = 0;

    void dfs(vector<int>& nums, int idx, int val) {
        if (idx == nums.size()) {
            ans += val;
            return;
        }

        dfs(nums, idx+1, val);
        dfs(nums, idx+1, val ^ nums[idx]);
    }

    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ans;
    }
};
// @lc code=end

