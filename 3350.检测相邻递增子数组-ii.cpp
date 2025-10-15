/*
 * @lc app=leetcode.cn id=3350 lang=cpp
 *
 * [3350] 检测相邻递增子数组 II
 */

// @lc code=start
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt = 1, precnt = 0, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                cnt++;
            } else {
                precnt = cnt;
                cnt = 1;
            }

            ans = max({ans, min(precnt, cnt), cnt/2});
        }

        return ans;
    }
};
// @lc code=end

