/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j, 0);
                }
            }
        }

        if (q.size() == n*n) return -1;

        int ans = -1;
        while(!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();

            ans = max(ans, d);

            for (int k = 0; k < dir.size(); k++) {
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.emplace(nx, ny, d+1);
                }
            }
        }

        return ans;
    }
};
// @lc code=end

