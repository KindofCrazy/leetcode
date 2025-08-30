/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& time, int totalTrips, long long now) {
        long long sum = 0;
        for (int t: time) {
            sum += now / t;
        }

        return sum >= totalTrips;
    }

    long long binarySearch(vector<int>& time, int totalTrips) {
        long long left = 1, right = (long long) totalTrips * *min_element(time.begin(), time.end());
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            if (check(time, totalTrips, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        return binarySearch(time, totalTrips);
    }
};
// @lc code=end

