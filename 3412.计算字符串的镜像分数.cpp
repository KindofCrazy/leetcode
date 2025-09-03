/*
 * @lc app=leetcode.cn id=3412 lang=cpp
 *
 * [3412] 计算字符串的镜像分数
 */

// @lc code=start
class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, vector<int>> mp;
        long long ans = 0;
        for (int j = 0; j < s.size(); j++) {
            if (mp[2*'a' + 25 - s[j]].size() > 0) {
                ans += (j - mp[2*'a' + 25 - s[j]].back());
                mp[2*'a' + 25 - s[j]].pop_back();
            } else {
                mp[s[j]].push_back(j);
            }
        }

        return ans;
    }
};
// @lc code=end

