/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> board = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    string path = "";
    vector<string> ans;

    void dfs(string digits, int idx) {
        if (idx == digits.size()) {
            ans.emplace_back(path);
            return;
        }

        for (char c: board[digits[idx]-'0']) {
            path.push_back(c);
            dfs(digits, idx+1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        
        dfs(digits, 0);

        return ans;
    }
};
// @lc code=end

