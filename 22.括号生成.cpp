/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:

    string s;
    vector<string> ans;

    void dfs(int n, int open, int close) {
        if (s.size() == 2*n) {
            ans.emplace_back(s);
        }

        if (open < n) {
            s.push_back('(');
            dfs(n, open+1, close);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            dfs(n, open, close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};
// @lc code=end

