/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 *
 * [1283] 使结果不超过阈值的最小除数
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums, int threshold, int query) {
        int sum = 0;
        for (int n: nums) {
            sum += ceil((double) n / query);
        }

        return sum <= threshold;
    }

    int binarySearch(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(nums, threshold, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        return binarySearch(nums, threshold);
    }
};
// @lc code=end

