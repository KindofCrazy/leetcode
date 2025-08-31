/*
 * @lc app=leetcode.cn id=2506 lang=cpp
 *
 * [2506] 统计相似字符串对的数目
 */

// @lc code=start
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (string word: words) {
            int mask = 0;
            for (char c: word) {
                mask |= 1 << (c - 'a');
            }

            ans += mp[mask];
            mp[mask]++;
        }

        return ans;
    }
};
// @lc code=end

