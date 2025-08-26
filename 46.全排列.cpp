/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int first) {
        if (first == nums.size() - 1) {
            ans.emplace_back(nums);
        }

        for (int i = first; i < nums.size(); i++) {
            swap(nums[first], nums[i]);
            backtrack(nums, first+1);
            swap(nums[first], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

