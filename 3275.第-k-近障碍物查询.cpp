/*
 * @lc app=leetcode.cn id=3275 lang=cpp
 *
 * [3275] 第 K 近障碍物查询
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> result;
        for (auto query: queries) {
            int dis = abs(query[0]) + abs(query[1]);
            if (pq.size() < k || dis < pq.top()) pq.push(dis);
            if (pq.size() > k) pq.pop();
            if (pq.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(pq.top());
            }
        }

        return result;
    }
};
// @lc code=end

