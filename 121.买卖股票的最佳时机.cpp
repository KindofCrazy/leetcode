/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, ans = 0;
        for (int n: prices) {
            ans = max(ans, n - minPrice);
            minPrice = min(minPrice, n);
        }
        return ans;
    }
};
// @lc code=end

