/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
    bool isOdd(int n) {
        return n % 2 == 1;
    }

    int solve (vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0, oddCount = 0;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && oddCount < k) {
                oddCount += isOdd(nums[right++]);
            }

            if (oddCount >= k && right > left) {
                ans += (n - right + 1);
            } else if (oddCount >= k && right == left) {
                ans += (n - right);
            }

            if (right > left) oddCount -= isOdd(nums[left]);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k+1);
    }
};
// @lc code=end

