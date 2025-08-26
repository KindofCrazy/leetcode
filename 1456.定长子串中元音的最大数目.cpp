/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0, count = 0;
        for (int i = 0; i < k-1; i++) {
            count += isVowel(s[i]);
        }

        for (int left = 0, right = k-1; right < n; left++, right++) {
            count += isVowel(s[right]);
            ans = max(ans, count);
            count -= isVowel(s[left]);
        }

        return ans;
    }
};
// @lc code=end

