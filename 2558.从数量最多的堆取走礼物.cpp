/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while (k--) {
            int x = sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }

        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

