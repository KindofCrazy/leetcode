/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int stackMethod(string s) {
        int slen = s.size();
        stack<int> stk;
        stk.push(-1); 

        int ans = 0;
        for (int i = 0; i < slen; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i-stk.top());
                }
            }
        }

        return ans;
    }

    int longestValidParentheses(string s) {
        int slen = s.size();
        vector<int> dp(slen, 0);

        for (int i = 1; i < slen; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = i >= 2? dp[i-2]+2: 2;
                } else {
                    int sublen = dp[i-1];
                    if (i > sublen && s[i-sublen-1] == '(') {
                        dp[i] = dp[i-1] + 2 + (i-sublen-2 >= 0? dp[i-sublen-2]: 0);
                    }
                }
            }
        }

        return slen == 0 ? 0 : ranges::max(dp);
    }
};
// @lc code=end

