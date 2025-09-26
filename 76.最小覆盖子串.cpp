/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */


// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;

        int valid = 0;
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;

        for (char c: t) {
            need[c]++;
        }
        while (right < s.size()) {
            char ch = s[right];
            if (need.count(ch)) {
                window[ch]++;
                if (need[ch] == window[ch]) valid++;
            }

            while (valid == need.size()) {
                if (right-left+1 < len) {
                    len = right-left+1;
                    start = left;
                }
                if (need.count(s[left])) {
                    window[s[left]]--;
                    if (need[s[left]] > window[s[left]]) valid--;
                }
                left++;
            }

            right++;
        }

        return len == INT_MAX ? "": s.substr(start, len);
    }

};
// @lc code=end

