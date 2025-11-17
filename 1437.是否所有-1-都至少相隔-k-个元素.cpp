/*
 * @lc app=leetcode.cn id=1437 lang=cpp
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 */

// @lc code=start
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int gap = k+1;
        for (int n: nums) {
            if (n == 1) {
                if (gap < k) {
                    return false;
                }
                gap = 0;
            } else {
                gap++;
            }
        }

        return true;
    }
};
// @lc code=end

