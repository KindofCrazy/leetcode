/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:

    vector<int> path;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            if (path.size() >= 2) {
                ans.emplace_back(path);
            }
            return;
        }

        if (path.empty() || nums[idx] >= path.back()) {
            path.push_back(nums[idx]);
            dfs(nums, idx+1);
            path.pop_back();
        }

        if (path.empty() || nums[idx] != path.back()) {
            dfs(nums, idx+1);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

