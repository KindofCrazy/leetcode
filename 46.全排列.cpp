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

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                arr.push_back(nums[i]);
                
                dfs(nums, idx+1);
                
                arr.pop_back();
                used[i] = false;
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

