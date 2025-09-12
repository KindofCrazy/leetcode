/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    vector<bool> used;
    vector<int> arr;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(arr);
            return;
        }

        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                arr.push_back(nums[i]);
                used[i] = true;
                dfs(nums, idx+1);
                used[i] = false;
                arr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

