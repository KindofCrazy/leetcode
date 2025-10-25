/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        int weekCnt = n / 7, dayCnt = n % 7;
        int weekVal = 28;
        int week = weekCnt * weekVal + weekCnt * (weekCnt-1) * 7/2;
        int ans = week;
        for (int i = 1; i <= dayCnt; i++) {
            ans += (weekCnt + i);
        }

        return ans;
    }
};
// @lc code=end

