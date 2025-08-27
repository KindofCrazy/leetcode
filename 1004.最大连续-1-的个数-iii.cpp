/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0, zeroCount = 0;
        for (int left = 0, right = 0; right < n; left++) {
            right = max(left, right);
            while(right < n && zeroCount + (nums[right] == 0) <= k) {
                zeroCount += (nums[right] == 0);
                right++;
            }

            ans = max(ans, right - left);
            if (right > left) zeroCount -= (nums[left] == 0);
        }

        return ans;
    }
};
// @lc code=end

