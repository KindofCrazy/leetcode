/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 *
 * [2815] 数组中的最大数对和
 */

// @lc code=start
class Solution {
public:
    int f(int n) {
        int ans = 0;
        while (n > 0) {
            ans = max(ans, n % 10);
            n /= 10;
        }
        return ans;
    }

    int maxSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int key = f(nums[i]);
            if (mp.count(key)) {
                ans = max(ans, nums[i] + mp[key]);
            }
            mp[key] = max(mp[key], nums[i]);
        }

        return ans;
    }
};
// @lc code=end

