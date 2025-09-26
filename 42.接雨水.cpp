/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n), right(n);
        int leftMax = 0, rightMax = 0;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            left[i] = leftMax - height[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            rightMax = max(rightMax, height[i]);
            right[i] = rightMax - height[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]);
        }

        return ans;
    }
};
// @lc code=end

