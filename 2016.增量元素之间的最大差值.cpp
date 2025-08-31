/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, minNum = INT_MAX;
        for (int n: nums) {
            if (n > minNum) ans = max(ans, n - minNum);
            minNum = min(minNum, n);
        }

        return ans;
    }
};
// @lc code=end

