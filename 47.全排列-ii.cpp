/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
                continue;
            }
            
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, idx+1);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

