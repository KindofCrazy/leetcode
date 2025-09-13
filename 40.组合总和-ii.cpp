/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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

        path.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx+1);
        path.pop_back();

        while (idx+1 < candidates.size() && candidates[idx] == candidates[idx+1]) {
            idx++;
        }
        dfs(candidates, target, idx+1);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

