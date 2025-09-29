/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& board, string word, int x, int y, int idx) {
        int m = board.size(), n = board[0].size();
        if (idx == word.size()) return true;
        if (x < 0 || x >=m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[idx]) {
            return false;
        }

        visited[x][y] = true;

        for (auto& [dx, dy]: dir) {
            if (dfs(board, word, x+dx, y+dy, idx+1)) {
                return true;
            }
        }

        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        } 

        return false;
    }
};
// @lc code=end

