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
        for (int i = 0; i < k-1; i++) {
            pq.push({nums[i], i});
        }

        vector<int> ans;
        for (int i = k-1; i < n; i++) {
            pq.push({nums[i], i});
            while (pq.top().second < i-k+1) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
// @lc code=end

