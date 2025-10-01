/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string getDigits(string& s, int& ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }

        return ret;
    }

    string decodeString(string s) {
        stack<string> stk;

        int ptr = 0;
        while (ptr < s.size()) {
            char c = s[ptr];
            if (isdigit(c)) {
                string digits = getDigits(s, ptr);
                stk.push(digits);
            } else if (isalpha(c) || c == '[') {
                stk.push(string(1, c));
                ptr++;
            } else {
                ptr++;

                string sub = "";
                while (stk.top() != "[") {
                    sub = stk.top() + sub;
                    stk.pop();
                }
                stk.pop();
                
                int repeat = stoi(stk.top());
                stk.pop();
                while (repeat--) {
                    stk.push(sub);
                }
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};
// @lc code=end

