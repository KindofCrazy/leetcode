/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0, zeroCount = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while(right < n && zeroCount <= 1) {
                zeroCount += !nums[right++];
            }

            ans = max(ans, right - left - max(zeroCount, 1));
            zeroCount -= !nums[left];
        }

        return ans;
    }
};
// @lc code=end

