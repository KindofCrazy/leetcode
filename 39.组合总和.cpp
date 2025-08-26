/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:

    vector<int> comb;
    vector<vector<int>> ans;
    void backtrack(vector<int>& candiates, int target, int index) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < candiates.size(); i++) {
            comb.push_back(candiates[i]);
            backtrack(candiates, target - candiates[i], i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

