/*
 * @lc app=leetcode.cn id=3461 lang=cpp
 *
 * [3461] 判断操作后字符串中的数字是否相等 I
 */

// @lc code=start
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string newString = "";
            for (int i = 0; i < s.size()-1; i++) {
                int a = s[i]-'0', b = s[i+1]-'0';
                int newc = (a + b) % 10;
                newString += to_string(newc);
            }

            s = newString;
        }

        return s[0] == s[1];
    }
};
// @lc code=end

