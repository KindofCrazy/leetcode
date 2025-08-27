/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;

        int ans = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while (right < n && (mp.size() <= 1 || mp.count(fruits[right]))) {
                mp[fruits[right++]]++;
            }

            ans = max(ans, right - left);
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0) {
                mp.erase(fruits[left]);
            }
        }

        return ans;
    }
};
// @lc code=end

