/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<int> arr;
    vector<vector<int>> ans;

    void dfs(int k, int n, int i) {
        if (arr.size() == k && n == 0) {
            ans.emplace_back(arr);
        }

        if (arr.size() + (9-i+1) < k) return;

        for (int j = i; j <= 9; j++) {
            arr.push_back(j);
            dfs(k, n-j, j+1);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
};
// @lc code=end

