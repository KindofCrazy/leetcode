/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int  i = 0, j = 0;
        stack<int> s;
        while (i < n) {
            s.push(pushed[i]);
            while (j < n && !s.empty() && popped[j] == s.top()) {
                s.pop();
                j++;
            }
            i++;
        }

        return s.empty();
    }
};
// @lc code=end

