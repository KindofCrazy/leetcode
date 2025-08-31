/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto pair: dominoes) {
            sort(pair.begin(), pair.end());
            int key = pair[0] * 10 + pair[1];
            ans += mp[key];
            mp[key]++;
        }

        return ans;
    }
};
// @lc code=end

