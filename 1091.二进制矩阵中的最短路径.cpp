/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
        vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};
        
        if (grid[0][0] == 1) return -1;
        
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 1);
        while (!q.empty()){
            auto [cx, cy, d] = q.front();
            q.pop();

            if (cx == n-1 && cy == n-1) return d;

            for (int k = 0; k < dx.size(); ++k){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    q.emplace(nx, ny, d+1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

