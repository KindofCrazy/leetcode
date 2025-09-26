/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> scount, pcount;

    bool check() {
        for (int i = 0; i < 26; i++) {
            if (scount[i] != pcount[i]) return false;
        }
        return true;
    }


    vector<int> findAnagrams(string s, string p) {
        scount.assign(26, 0);
        pcount.assign(26, 0);
        int slen = s.size(), plen = p.size();
        for (char c: p) {
            pcount[c-'a']++;
        }

        for (int i = 0; i < plen-1 && i < slen; i++) {
            scount[s[i]-'a']++;
        }

        vector<int> ans;
        for (int i = 0; i <= slen-plen; i++) {
            scount[s[i+plen-1]-'a']++;
            if (check()) ans.push_back(i);
            scount[s[i]-'a']--;
        }

        return ans;
    }
};
// @lc code=end

