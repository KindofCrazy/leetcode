/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 *
 * [2441] 与对应负数同时存在的最大正整数
 */

// @lc code=start
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> occ(nums.begin(), nums.end());
        int ans = -1;
        for (int n: nums) {
            if (occ.count(-n)) {
                ans = max(ans, abs(n));
            }
        }

        return ans;
    }
};
// @lc code=end

