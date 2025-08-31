/*
 * @lc app=leetcode.cn id=2260 lang=cpp
 *
 * [2260] 必须拿起的最小连续卡牌数
 */

// @lc code=start
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < cards.size(); i++) {
            if (mp.count(cards[i])) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }

        return ans == INT_MAX? -1: ans;
    }
};
// @lc code=end

