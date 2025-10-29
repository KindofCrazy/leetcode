/*
 * @lc app=leetcode.cn id=3370 lang=cpp
 *
 * [3370] 仅含置位位的最小整数
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans < n) {
            ans = 2 * ans + 1;
        }

        return ans;
    }
};
// @lc code=end

