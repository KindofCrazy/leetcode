/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightMost = 0;
        for (int i = 0; i < nums.size() && i <= rightMost; i++) {
            rightMost = max(rightMost, i+nums[i]);
        }

        return rightMost >= nums.size()-1;
    }
};
// @lc code=end

