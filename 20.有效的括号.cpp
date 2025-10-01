/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty() || c != mp[stk.top()]) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
// @lc code=end

