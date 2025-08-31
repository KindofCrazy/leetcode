/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[k - nums[i]] > 0) {
                ans++;
                mp[k - nums[i]]--;
            } else {
                mp[nums[i]]++;
            }
        }

        return ans;
    }
};
// @lc code=end

