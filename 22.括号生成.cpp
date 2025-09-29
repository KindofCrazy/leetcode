/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    string path;
    vector<string> ans;

    void dfs(int n, int open, int close) {
        if (path.size() == 2*n) {
            ans.emplace_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            dfs(n, open+1, close);
            path.pop_back();
        }

        if (close < open) {
            path.push_back(')');
            dfs(n, open, close+1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        
        return ans;
    }
};
// @lc code=end

