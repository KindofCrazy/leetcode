/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long ans = 0;
        while(k--) {
            int num = pq.top();
            ans += num;
            pq.pop();
            pq.push(ceil((double) num / 3));
        }

        return ans;
    }
};
// @lc code=end

