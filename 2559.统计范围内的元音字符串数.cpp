/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isVowelString(string s) {
        int len = s.size();
        return isVowelLetter(s[0]) && isVowelLetter(s[len-1]);
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ps(words.size() + 1);
        for (int i = 0; i < words.size(); i++) {
            ps[i + 1] = ps[i] + isVowelString(words[i]);
        }

        vector<int> ans;
        for (auto query: queries) {
            ans.push_back(ps[query[1] + 1] - ps[query[0]]);
        }

        return ans;
    }
};
// @lc code=end

