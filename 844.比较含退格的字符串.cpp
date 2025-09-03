/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s) {
        string ret;
        for (char c: s) {
            if (c != '#') {
                ret.push_back(c);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }

        return ret;
    }
};
// @lc code=end

