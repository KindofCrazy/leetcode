/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, rightMost = 0, stepMost = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > stepMost) {
                ans++;
                stepMost = rightMost;
            }

            rightMost = max(rightMost, i+nums[i]);
        }

        return ans;
    } 
};
// @lc code=end

