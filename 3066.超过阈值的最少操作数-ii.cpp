/*
 * @lc app=leetcode.cn id=3066 lang=cpp
 *
 * [3066] 超过阈值的最少操作数 II
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int ans = 0;
        while (pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            ans++;
        }

        return ans;
    }
};
// @lc code=end

