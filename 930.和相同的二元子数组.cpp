/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int solve (vector<int>& nums, int goal) {
        int n = nums.size();
        
        int ans = 0, sum = 0;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && sum < goal) {
                sum += nums[right++];
            }

            if (sum >= goal && right > left) ans += (n - right + 1);
            else if (sum >= goal && right == left) ans += (n - right);
            /* Handle when goal == 0 */
            if (right > left) sum -= nums[left];
        }

        return ans;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal+1);
    }
};
// @lc code=end

