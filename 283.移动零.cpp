/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int left = 0, right = 0; right < n; right++) {
            if (nums[right] != 0) {
                swap(nums[left++], nums[right]);
            }
        }
    }
};
// @lc code=end
