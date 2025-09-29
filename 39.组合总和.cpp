/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.emplace_back(path);
            return;
        } else if (target < 0 || idx == candidates.size()) {
            return;
        }

        dfs(candidates, target, idx+1);

        path.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx);
        path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);

        return ans;
    }
};
// @lc code=end

