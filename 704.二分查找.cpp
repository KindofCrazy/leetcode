/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 2);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    int search(vector<int>& nums, int target) {
        int pos = binarySearch(nums, target);
        if (pos == nums.size() || nums[pos] != target) {
            return -1;
        }

        return pos;
    }
};
// @lc code=end

