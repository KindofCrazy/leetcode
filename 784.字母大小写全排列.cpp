/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:

    string res;
    vector<string> ans;

    void dfs(string s, int idx) {
        if (idx == s.size()) {
            ans.emplace_back(res);
            return;
        }

        res.push_back(s[idx]);
        dfs(s, idx+1);
        res.pop_back();

        if (islower(s[idx])) {
            res.push_back(toupper(s[idx]));
            dfs(s, idx+1);
            res.pop_back();
        } else if (isupper(s[idx])) {
            res.push_back(tolower(s[idx]));
            dfs(s, idx+1);
            res.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};
// @lc code=end

