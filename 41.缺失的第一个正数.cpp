/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }

        for (int i = 0; i < n; i++) {
            int key = abs(nums[i]);
            if (key > 0 && key <= n) {
                nums[key-1] = -abs(nums[key-1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }

        return n+1;
    }
};
// @lc code=end

