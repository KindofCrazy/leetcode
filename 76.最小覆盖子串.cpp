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
        for (char c : t) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            char c = s[right];

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (valid == need.size()) {
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }

                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
            
            right++;
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }

};
// @lc code=end

