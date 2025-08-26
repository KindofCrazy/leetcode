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
        unordered_set<char> set;

        int length = 0;
        for (int l = 0, r = 0; r < n; r++) {
            char c = s[r];
            while(l <= r && set.count(c)) {
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);
            length = max(length, r-l+1);
        }
        return length;
    }
};
// @lc code=end

