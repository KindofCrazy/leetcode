/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
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

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        for (int n: arr1) {
            int pos = binarySearch(arr2, n);
            int dis1 = pos == arr2.size()? INT_MAX: abs(n - arr2[pos]);
            int dis2 = pos == 0? INT_MAX: abs(n - arr2[pos-1]);
            if (min(dis1, dis2) > d) {
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

