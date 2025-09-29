/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:

    vector<int> cols;
    unordered_set<int> occCols, occDiag1, occDiag2;
    vector<vector<string>> ans;

    void dfs(int n, int r) {
        if (r == n) {
            ans.emplace_back(generate());
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!occCols.count(c) && !occDiag1.count(r+c) && !occDiag2.count(r-c)) {
                occCols.insert(c);
                occDiag1.insert(r+c);
                occDiag2.insert(r-c);
                cols.push_back(c);

                dfs(n, r+1);
                
                cols.pop_back();
                occCols.erase(c);
                occDiag1.erase(r+c);
                occDiag2.erase(r-c);
            }
        }
    }

    vector<string> generate() {
        vector<string> board;
        for (int i = 0; i < cols.size(); i++) {
            string row(cols.size(), '.');
            row[cols[i]] = 'Q';
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

