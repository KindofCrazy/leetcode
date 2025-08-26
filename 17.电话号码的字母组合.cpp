/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    string s;
    vector<string> ans;
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(string digits, int cur) {
        if (cur == digits.size()) {
            ans.push_back(s);
            return;
        }
        
        for (char c: mp[digits[cur]]) {
            s.push_back(c);
            backtrack(digits, cur+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        backtrack(digits, 0);
        return ans;
    }
};
// @lc code=end

