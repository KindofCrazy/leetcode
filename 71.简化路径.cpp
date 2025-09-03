/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> files;

        string token;
        for (int i = 0; i <= n; i++) {
            if (i == n || path[i] == '/') {
                if (token == ".") {
                    /* do nothing */
                } else if (token == "..") {
                    if (!files.empty()) files.pop();
                } else {
                    if (!token.empty()) files.push(token);
                }
                token.clear();
            } else {
                token.push_back(path[i]);
            }
        }

        string ans = "";
        if (files.empty()) {
            return "/";
        }
        while (!files.empty()) {
            ans = ("/" + files.top()) + ans;
            files.pop();
        }

        return ans;
    }
};
// @lc code=end

