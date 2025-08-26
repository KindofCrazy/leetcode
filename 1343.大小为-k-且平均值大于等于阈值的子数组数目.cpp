/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0, sumThreshold = threshold * k;
        for (int i = 0; i < k-1; i++) {
            sum += arr[i];
        }

        int ans = 0;
        for (int left = 0, right = k-1; right < n; left++, right++) {
            sum += arr[right];
            if (sum >= sumThreshold) {
                ans++;
            }
            sum -= arr[left];
        }

        return ans;
    }
};
// @lc code=end

