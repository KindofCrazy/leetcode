/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 *
 * [2606] 找到最大开销的子字符串
 */

// @lc code=start
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        vector<int> map(26);
        for (int i = 0; i < 26; i++) {
            map[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            map[chars[i] - 'a'] = vals[i];
        }

        int res = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int cost = map[s[i] - 'a'];
            cur = max(cur + cost, cost);
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end

