/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<int> set;
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int cur) {
        if(cur == nums.size()) {
            ans.emplace_back(set);
            return;
        }
    
        set.push_back(nums[cur]);
        backtrack(nums, cur+1);
        set.pop_back();
        backtrack(nums, cur+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

