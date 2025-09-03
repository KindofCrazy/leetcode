/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> idx;
        for (int i = 0; i < n; i++) {
            idx.push(i);
        }
        
        sort(deck.begin(), deck.end());
        vector<int> ans(n);
        for (int card: deck) {
            ans[idx.front()] = card;
            idx.pop();
            if (!idx.empty()) {
                idx.push(idx.front());
                idx.pop();
            }
        }

        return ans;
    }
};
// @lc code=end

