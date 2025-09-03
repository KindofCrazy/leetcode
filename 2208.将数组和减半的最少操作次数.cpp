/*
 * @lc app=leetcode.cn id=2208 lang=cpp
 *
 * [2208] 将数组和减半的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double target = sum / 2;

        priority_queue<double> pq(nums.begin(), nums.end());

        int ans = 0;
        double reduced = 0;
        while (reduced < target) {
            double x = pq.top();
            reduced += x / 2;
            pq.pop();
            pq.push(x / 2);
            ans++;
        }
        return ans;
    }
};
// @lc code=end

