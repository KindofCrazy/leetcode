/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        unordered_map<char, int> mp;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && mp.size() < 3) {
                mp[s[right++]]++;
            }   

            if (mp.size() == 3) {
                ans += (n - right + 1);
            }

            mp[s[left]]--;
            if (mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
        }

        return ans;
    }
};
// @lc code=end

