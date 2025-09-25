/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].emplace_back(s);
        }

        vector<vector<string>> ans;
        for (auto &[key, v]: mp) {
            ans.emplace_back(v);
        }

        return ans;
    }
};
// @lc code=end

