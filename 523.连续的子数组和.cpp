/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> occ;
        occ.insert(0);

        long long sum = nums[0], lastSum = sum;
        for (int i = 1; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if (occ.contains(sum)) return true;
            occ.insert(lastSum);
            lastSum = sum;
        }

        return false;
    }
};
// @lc code=end

