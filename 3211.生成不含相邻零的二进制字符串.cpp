/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 *
 * [3211] 生成不含相邻零的二进制字符串
 */

// @lc code=start
class Solution {
public:

    string s;
    vector<string> ans;

    void dfs(int n, int idx) {
        if (idx == n) {
            ans.emplace_back(s);
            return;
        }

        s.push_back('1');
        dfs(n, idx+1);
        s.pop_back();

        if (s.empty() || s.back() != '0') {
            s.push_back('0');
            dfs(n, idx+1);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        dfs(n, 0);
        return ans;
    }
};
// @lc code=end

