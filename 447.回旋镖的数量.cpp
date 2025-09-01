/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int distance(vector<int> a, vector<int> b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = 0, ans = 0;
        for (auto p: points) {
            unordered_map<int, int> mp;
            for (auto q: points) {
                int dis = distance(p, q);
                mp[dis]++;
            }

            for (auto &[_, m]: mp) {
                ans += m * (m - 1);
            }
        }

        return ans;
    }
};
// @lc code=end

