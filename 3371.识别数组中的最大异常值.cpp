/*
 * @lc app=leetcode.cn id=3371 lang=cpp
 *
 * [3371] 识别数组中的最大异常值
 */

// @lc code=start
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans = INT_MIN;
        int total = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int n: nums) {
            if ((total - n) % 2 == 0) {
                int key = (total - n) / 2;
                if ((key != n && mp[key] > 0) || (key == n && mp[key] > 1)) {
                    ans = max(ans, n);
                }
            }
        }

        return ans == INT_MIN? -1: ans;
    }
};
// @lc code=end

