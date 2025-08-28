/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MAX, sum = 0;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while(right < n && sum < target) {
                sum += nums[right++];
            }
            
            if (sum >= target) {
                ans = min(ans, right - left);
            }

            if (right > left)  sum -= nums[left];
        }

        return ans == INT_MAX? 0: ans;
    }
};
// @lc code=end

