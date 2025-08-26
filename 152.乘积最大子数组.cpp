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
        vector<int> dpMin(n), dpMax(n);

        dpMin[0] = nums[0];
        dpMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int maxVal = nums[i], minVal = nums[i];
            maxVal = max(nums[i]*dpMin[i-1], maxVal);
            maxVal = max(nums[i]*dpMax[i-1], maxVal);
            minVal = min(nums[i]*dpMin[i-1], minVal);
            minVal = min(nums[i]*dpMax[i-1], minVal);

            dpMin[i] = minVal;
            dpMax[i] = maxVal;
        }
        return *max_element(dpMax.begin(), dpMax.end());
    }
};
// @lc code=end

