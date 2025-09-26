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
        for (int left = 0, right = 0; right < n; right++) {
            while (occ.contains(s[right])) {
                occ.erase(s[left++]);
            }

            occ.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
// @lc code=end

