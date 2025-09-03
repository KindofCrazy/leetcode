/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int n = pq.top();
            pq.pop();
            pq.push(n - (n / 2));
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

