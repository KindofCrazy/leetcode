/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> occ;

        int ans = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while (!occ.count(s[right]) && right < n) {
                occ.insert(s[right++]);
            }
            ans = max(ans, right - left);
            occ.erase(s[left]);
        }

        return ans;
    }
};
// @lc code=end

