/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 1, minVal = 1, ans = INT_MIN;
        for (int n: nums) {
            int tmp = maxVal;
            maxVal = max({n, maxVal*n, minVal*n});
            minVal = min({n, tmp*n, minVal*n});
            ans = max(ans, maxVal);
        }

        return ans;
    }
};
// @lc code=end

