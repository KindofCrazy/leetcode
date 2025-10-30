/*
 * @lc app=leetcode.cn id=1526 lang=cpp
 *
 * [1526] 形成目标数组的子数组最少增加次数
 */

// @lc code=start
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); i++) {
            ans += max(target[i]-target[i-1], 0);
        }

        return ans;
    }
};
// @lc code=end

