/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 *
 * [3296] 移山所需的最少秒数
 */

// @lc code=start
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using P = pair<long long, int>;
        auto cmp = [](const P& a, const P& b) {
            long long ta = a.first * a.second * (a.second+1) / 2;
            long long tb = b.first * b.second * (b.second+1) / 2;
            return ta > tb;  
        };


        priority_queue<P, vector<P>, decltype(cmp)> pq;
        for (int w: workerTimes) {
            pq.emplace(w, 1);
        }

        long long ans = 0;
        while(mountainHeight > 0) {
            auto [t, k] = pq.top();
            pq.pop();
            mountainHeight--;
            ans = max(ans, t*k*(k+1)/2);
            pq.emplace(t, k+1);
        }

        return ans;
    }
};
// @lc code=end

