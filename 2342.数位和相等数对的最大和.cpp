/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution {
public:
    long long f(int n) {
        long long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<long long, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(f(nums[i]))) {
                ans = max(ans, mp[f(nums[i])] + nums[i]);
            }
            mp[f(nums[i])] = max(mp[f(nums[i])], nums[i]);
        }

        return ans;
    }
};
// @lc code=end

