/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int n: nums) {
            ans += mp[n];
            mp[n]++;
        }
        
        return ans;
    }
};
// @lc code=end

