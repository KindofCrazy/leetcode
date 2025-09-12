/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<string> sub;
    vector<vector<string>> ans;

    void dfs(string s, int idx) {
        if (idx == s.size()) {
            ans.emplace_back(sub);
            return;
        }

        for (int end = idx; end < s.size(); end++) {
            string t = s.substr(idx, end-idx+1), a = t;
            reverse(a.begin(), a.end());
            if (a == t) {
                sub.emplace_back(t);
                dfs(s, end+1);
                sub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
// @lc code=end

