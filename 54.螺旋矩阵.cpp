/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> ans;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int count = 0;

        int row = 0, col = 0;
        int directionIndex = 0;
        while(count < rows*cols) {
            ans.push_back(matrix[row][col]);
            visited[row][col] = true;
            count++;
            int nextRow = row + directions[directionIndex][0], nextCol = col + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || visited[nextRow][nextCol]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row = row + directions[directionIndex][0];
            col = col + directions[directionIndex][1];
        }
        return ans;
    }
};
// @lc code=end

