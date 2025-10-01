/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> stk;
        vector<int> left(n, -1), right(n, n);

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i], r = right[i];
            ans = max(ans, (r-l-1)*heights[i]);
        }

        return ans;
    }
};
// @lc code=end

