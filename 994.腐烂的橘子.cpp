/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1 ,0}};
        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto pos = q.front();
                q.pop();
                for (auto d: directions) {
                    int newX = pos.first + d[0], newY = pos.second + d[1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                        if (grid[newX][newY] == 1) {
                            grid[newX][newY] = 2;
                            count--;
                            q.push({newX, newY});
                        }
                    }
                }
            }
            if (q.empty()) break;
            step++;
        }

        if (count > 0) {
            return -1;
        } else {
            return step;
        }
    }
};
// @lc code=end

