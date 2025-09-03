/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        string ans;
        for (char c: s) {
            if (c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }   
        }

        return ans;
    }
};
// @lc code=end

