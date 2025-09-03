/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int s: stones) {
            pq.push(s);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a > b) {
                pq.push(a - b);
            }
        }

        if (pq.empty()) return 0;
        return pq.top();
    }
};
// @lc code=end

