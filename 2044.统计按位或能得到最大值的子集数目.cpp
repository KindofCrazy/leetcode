/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int cnt = 0;

    void dfs(vector<int>& nums, int idx, int val) {
        if (idx == nums.size()) {
            if (val > ans) {
                ans = val;
                cnt = 1;
            } else if (val == ans) {
                cnt++;
            }
            return;
        }

        dfs(nums, idx+1, val);
        dfs(nums, idx+1, val | nums[idx]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        dfs(nums, 0, 0);
        return cnt;
    }
};
// @lc code=end

