/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        cnt[0] = 1;

        int ans = 0;

        long long sum = 0;
        for (int n: nums) {
            sum = (sum + n) % k;
            while (sum < 0) {
                sum += k;
            } 
            ans += cnt[sum];
            cnt[sum]++;
        }

        return ans;
    }
};
// @lc code=end

