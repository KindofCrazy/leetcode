/*
 * @lc app=leetcode.cn id=3228 lang=cpp
 *
 * [3228] 将 1 移动到末尾的最大操作次数
 */

// @lc code=start
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ans = 0, ones = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else if (i > 0 && s[i-1] == '1') {
                ans += ones;
            }
        }

        return ans;
    }
};
// @lc code=end

