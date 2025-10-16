/*
 * @lc app=leetcode.cn id=2598 lang=cpp
 *
 * [2598] 执行操作后的最大 MEX
 */

// @lc code=start
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);
        
        for (int num: nums) {
            int mod = ((num % value) + value) % value;
            cnt[mod]++;
        }

        int ans = 0;
        while (true) {
            int mod = ans % value;
            if (cnt[mod] == 0) {
                return ans;
            }
            cnt[mod]--;
            ans++;
        }

        return ans;
    }
};
// @lc code=end

