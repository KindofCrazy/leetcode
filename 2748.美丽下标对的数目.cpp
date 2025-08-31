/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 *
 * [2748] 美丽下标对的数目
 */

// @lc code=start
class Solution {
public:
    int first(int n) {
        while (n >= 10) {
            n /= 10;
        }

        return n;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int last = nums[i] % 10;
            for (int j = 1; j < 10; j++) {
                if (gcd(j, last) == 1) {
                    ans += mp[j];
                } 
            }

            mp[first(nums[i])]++;
        }

        return ans;
    }
};
// @lc code=end

