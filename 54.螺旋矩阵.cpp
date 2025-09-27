/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int count = 0, row = 0, col = 0, dir = 0;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> ans;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while (count < m * n) {
            ans.push_back(matrix[row][col]);
            visited[row][col] = true;
            count++;

            int nextRow = row + directions[dir][0];
            int nextCol = col + directions[dir][1];
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol]) {
                dir = (dir + 1) % directions.size();
            }

            row = row + directions[dir][0];
            col = col + directions[dir][1];
        }

        return ans;
    }
};
// @lc code=end

