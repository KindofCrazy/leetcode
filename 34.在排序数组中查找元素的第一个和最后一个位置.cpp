/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binarySearch(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }

        int end = binarySearch(nums, target + 1) - 1;
        return {start, end};
    }
};
// @lc code=end

