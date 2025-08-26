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
        vector<int> leftmax(n), rightmax(n);
        int lm = height[0], rm = height[n-1];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            lm = max(lm, height[i]);
            leftmax[i] = lm - height[i];

            rm = max(rm, height[n-1-i]);
            rightmax[n-1-i] = rm - height[n-1-i];
        }
        for (int i = 0; i < n; i++) {
            ans += min(leftmax[i], rightmax[i]);
        }
        return ans;
    }
};
// @lc code=end

