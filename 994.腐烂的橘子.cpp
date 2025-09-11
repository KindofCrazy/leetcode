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

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int num = 0, cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.emplace(i, j);
                if (grid[i][j] == 1) num++;
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < dir.size(); k++) {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.emplace(nx, ny);
                        cnt++;
                    }
                }
            }

            ans += !q.empty();
        }

        if (cnt == num) return ans;
        return -1;
    }
};
// @lc code=end

