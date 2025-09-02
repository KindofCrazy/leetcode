/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
class Solution {
public:
    int pre(int x) {
        return x / 2;
    }

    int countOdds(int low, int high) {
        return pre(high + 1) - pre(low);
    }
};
// @lc code=end

