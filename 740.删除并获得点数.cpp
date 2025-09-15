/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
public:

    int rob(vector<int>& nums) {
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int tmp = max(first + nums[i], second);
            first = second;
            second = tmp;
        }

        return second;
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int n: nums) {
            maxVal = max(n, maxVal);
        }

        vector<int> sum(maxVal+1);
        for (int n: nums) {
            sum[n] += n;
        }
        return rob(sum);
    }
};
// @lc code=end

