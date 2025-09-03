/*
 * @lc app=leetcode.cn id=2233 lang=cpp
 *
 * [2233] K 次增加后的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
        }

        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % ((int) pow(10, 9) + 7);
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

