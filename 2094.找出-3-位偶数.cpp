/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */

// @lc code=start
class Solution {
public:

    int path = 0;
    vector<bool> used;
    vector<int> ans;

    void dfs(vector<int>& digits, int idx) {
        if (idx == 3) {
            if (path % 2 == 0) ans.emplace_back(path);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i] || (i > 0 && digits[i] == digits[i-1] && !used[i-1])) continue;
            if (idx == 0 && digits[i] == 0) continue;

            path = path * 10 + digits[i];
            used[i] = true;
            dfs(digits, idx+1);
            path = path / 10;
            used[i] = false;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        used.assign(digits.size(), false);
        sort(digits.begin(), digits.end());
        dfs(digits, 0);

        return ans;
    }
};
// @lc code=end

