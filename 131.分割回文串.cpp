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
            string ss = s.substr(idx, end-idx+1);
            string fs = ss;
            reverse(fs.begin(), fs.end());

            if (ss == fs) {
                sub.emplace_back(ss);
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

