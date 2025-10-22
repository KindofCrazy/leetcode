/*
 * @lc app=leetcode.cn id=3347 lang=cpp
 *
 * [3347] 执行操作后元素的最高频率 II
 */

// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> diff;

        for (int x: nums) {
            cnt[x]++;
            diff[x];
            diff[x-k]++;
            diff[x+k+1]--;
        }

        int ans = 0, sumD = 0;
        for (auto& [x, d]: diff) {
            sumD += d;
            ans = max(ans, min(sumD, cnt[x]+numOperations));
        }

        return ans;
    }
};
// @lc code=end

