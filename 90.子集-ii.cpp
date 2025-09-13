/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        
        path.push_back(nums[idx]);
        dfs(nums, idx+1);
        path.pop_back();

        while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }
        dfs(nums, idx+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

