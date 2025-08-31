/*
 * @lc app=leetcode.cn id=2001 lang=cpp
 *
 * [2001] 可互换矩形的组数
 */

// @lc code=start
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        unordered_map<double, long long> mp;
        for (auto rectangle: rectangles) {
            double ratio = (double) rectangle[0] / rectangle[1];
            ans += mp[ratio];
            mp[ratio]++;
        }

        return ans;
    }
};
// @lc code=end

