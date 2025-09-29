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
        vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& [dirx, diry]: directions) {
                    int newx = x + dirx, newy = y + diry;
                    if (newx < 0 || newx >= m || newy < 0 || newy >= n || grid[newx][newy] != 1) {
                        continue;
                    }

                    q.emplace(newx, newy);
                    grid[newx][newy] = 2;
                }
            }

            ans += !q.empty();
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};
// @lc code=end

