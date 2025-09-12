/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:

    vector<int> res;
    vector<vector<int>> ans;

    void dfs(int n, int k, int a) {
        if ((n-a+1) + res.size() < k) {
            return;
        }

        if (res.size() == k) {
            ans.emplace_back(res);
        }
        for (int i = a; i <= n; i++) {
            res.push_back(i);
            dfs(n, k, i+1);
            res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};
// @lc code=end

