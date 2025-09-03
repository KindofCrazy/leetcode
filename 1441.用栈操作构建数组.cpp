/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 0;
        for (int i = 1; i <= n && idx < target.size(); i++) {
            ans.push_back("Push");
            if (target[idx] > i) {
                ans.push_back("Pop");
            } else {
                idx++;
            }
        }
        return ans;
    }
};
// @lc code=end

