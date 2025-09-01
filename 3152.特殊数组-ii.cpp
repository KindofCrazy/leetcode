/*
 * @lc app=leetcode.cn id=3152 lang=cpp
 *
 * [3152] 特殊数组 II
 */

// @lc code=start
class Solution {
public:
    bool isSpecial(int a, int b) {
        if (a % 2 == b % 2) return false;
        else return true;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ps(n + 1);
        for (int i = 1; i < n; i++) {
            ps[i+1] = ps[i] + isSpecial(nums[i-1], nums[i]);
        }

        vector<bool> ans;
        for (auto query: queries) {
            ans.push_back(ps[query[1]+1] - ps[query[0]+1] == query[1] - query[0]);
        }

        return ans;
    }
};
// @lc code=end

