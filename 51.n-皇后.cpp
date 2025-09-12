/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<int> columns;
    unordered_set<int> occColumns, occDiag1, occDiag2;
    vector<vector<string>> ans;

    void dfs(int n, int idx) {
        if (idx == n) {
            ans.push_back(generate());
            return;
        }

        int row = idx;
        for (int col = 0; col < n; col++) {
            if (!occColumns.count(col) && !occDiag1.count(row+col) && !occDiag2.count(row-col)) {
                columns.push_back(col);
                occColumns.insert(col);
                occDiag1.insert(row+col);
                occDiag2.insert(row-col);

                dfs(n, idx+1);

                columns.pop_back();
                occColumns.erase(col);
                occDiag1.erase(row+col);
                occDiag2.erase(row-col);
            }
        }
    }

    vector<string> generate() {
        vector<string> board;
        for (int i = 0; i < columns.size(); i++) {
            string row = string(columns.size(), '.');
            row[columns[i]] = 'Q';
            board.emplace_back(row);
        }
        return board;
    }

    vector<vector<string>> solveNQueens(int n) {
        dfs(n, 0);
        return ans;
    }
};
// @lc code=end

