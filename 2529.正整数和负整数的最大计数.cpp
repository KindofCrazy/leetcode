/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int posStart = binarySearch(nums, 1);
        int negEnd = binarySearch(nums, 0) - 1;
        int posNum = nums.size() - posStart, negNum = negEnd + 1;
        return max(posNum, negNum);
    }
};
// @lc code=end

