/*
 * @lc app=leetcode.cn id=1578 lang=cpp
 *
 * [1578] 使绳子变成彩色的最短时间
 */

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char ballon = colors[0];
        int total = 0, mx = 0, ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (ballon == colors[i]) {
                total += neededTime[i];
                mx = max(mx, neededTime[i]);
            } else {
                ans += (total - mx);
                ballon = colors[i];
                total = neededTime[i];
                mx = neededTime[i];
            }
        }

        ans += (total -mx);
        return ans;
    }
};
// @lc code=end

