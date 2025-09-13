/*
 * @lc app=leetcode.cn id=1415 lang=cpp
 *
 * [1415] 长度为 n 的开心字符串中字典序第 k 小的字符串
 */

// @lc code=start
class Solution {
public:
    string path;
    vector<string> ans;

    void dfs(int n, int idx) {
        if (idx == n) {
            ans.emplace_back(path);
            return;
        }

        for (int i = 0; i < 3; i++) {
            char c = i + 'a';
            if (path.empty() || c != path.back()) {
                path.push_back(c);
                dfs(n, idx+1);
                path.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        dfs(n, 0);
        if (k > ans.size()) return "";
        return ans[k-1];
    }
};
// @lc code=end

