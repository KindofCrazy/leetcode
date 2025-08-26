/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> scount = vector<int>(26);
    vector<int> pcount = vector<int>(26);

    bool check() {
        for (int i = 0; i < 26; i++) {
            if (scount[i] != pcount[i]) return false;
        }
        return true;
    }


    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();

        for (int i = 0; i < plen; i++) {
            pcount[p[i]-'a']++;
            if (i < plen-1 && i < slen) scount[s[i]-'a']++;
        }

        vector<int> ans;
        for (int left = 0; left <= slen-plen; left++) {
            int right = left + plen - 1;
            scount[s[right]-'a']++;
            if (check()) ans.push_back(left);
            scount[s[left]-'a']--;
        }
        return ans;
    }
};
// @lc code=end

