/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (lower) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return lower? left: left-1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false);

        if (leftIndex >= nums.size() || rightIndex < 0 || leftIndex > rightIndex) {
            return {-1, -1};
        }

        return {leftIndex, rightIndex};
    }
};
// @lc code=end

