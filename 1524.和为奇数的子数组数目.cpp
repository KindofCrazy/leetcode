/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 *
 * [1524] 和为奇数的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt[2] = {1, 0};
        int ans = 0;

        long long sum = 0;
        for (int n: arr) {
            sum += n;
            ans = (ans + cnt[(sum+1)% 2]) % ((int) pow(10, 9) + 7);
            cnt[sum%2]++;
        }

        return ans;
    }
};
// @lc code=end

