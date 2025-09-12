/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<int> set;
    vector<vector<int>> ans;
    
    void dfs(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(set);
            return;
        }

        dfs(nums, idx+1);

        set.push_back(nums[idx]);
        dfs(nums, idx+1);
        set.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

