/*
 * @lc app=leetcode.cn id=2226 lang=cpp
 *
 * [2226] 每个小孩最多能分到多少糖果
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums, long long query, long long k) {
        if (query == 0) return true;
        long long sum = 0;
        for (int n: nums) {
            sum += n / query;
        }

        return sum >= k;
    }

    int binarySearch(vector<int>& nums, long long k) {
        long long left = 0, right = (long long) *max_element(nums.begin(), nums.end());
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            if (check(nums, mid, k)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        return binarySearch(candies, k);
    }
};
// @lc code=end

