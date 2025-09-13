/*
 * @lc app=leetcode.cn id=967 lang=cpp
 *
 * [967] 连续差相同的数字
 */

// @lc code=start
class Solution {
public:
    
    string path;
    vector<int> ans;

    void dfs(int n, int k, int idx) {
        if (idx == n) {
            ans.push_back(stoi(path));
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (i == 0 && idx == 0) continue;
            if (path.empty() || abs(i - (path.back() - '0')) == k) {
                path.push_back(i + '0');
                dfs(n, k, idx+1);
                path.pop_back();
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        dfs(n, k, 0);
        return ans;
    }
};
// @lc code=end

