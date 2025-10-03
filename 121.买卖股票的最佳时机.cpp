/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minPrice = INT_MAX;

        for (int price: prices) {
            ans = max(ans, price-minPrice);
            minPrice = min(minPrice, price);
        }

        return ans;
    }
};
// @lc code=end

