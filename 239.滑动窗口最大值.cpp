/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for (int i = 0; i < k -1; i++) {
            pq.emplace(nums[i], i);
        }
        for (int left = 0; left <= n - k; left++) {
            int right = left+k-1;
            pq.emplace(nums[right], right);
            while(pq.top().second < left) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
// @lc code=end

