/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            cost[i] = abs(s[i] - t[i]);
        }

        int ans = 0, tmpCost = 0;
        for (int left = 0, right = 0; right < n; left++) {
            right = max(right, left);
            while (right < n && tmpCost + cost[right] <= maxCost) {
                tmpCost += cost[right++];
            }

            ans = max(ans, right - left);
            if(right > left) tmpCost -= cost[left];
        }

        return ans;
    }
};
// @lc code=end

