/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    string s;
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<char>>& board, string word, int r, int c) {
        if (s.size() == word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || word[s.size()] != board[r][c]) {
            return false;
        } 

        s.push_back(board[r][c]);
        visited[r][c] = true;

        for (auto &[dx, dy]: dir) {
            if (dfs(board, word, r+dx, c+dy)) {
                return true;
            }
        }

        s.pop_back();
        visited[r][c] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

