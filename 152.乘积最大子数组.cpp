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

        int ans = INT_MIN, maxVal = 1, minVal = 1;
        for (int n: nums) {
            int tmpMax = maxVal, tmpMin = minVal;
            maxVal = max({n, tmpMax*n, tmpMin*n});
            minVal = min({n, tmpMax*n, tmpMin*n});
            ans = max(ans, maxVal);
        }

        return ans;
    }
};
// @lc code=end
