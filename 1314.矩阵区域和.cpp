/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + mat[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rowMin = max(0, i-k), rowMax = min(m-1, i+k);
                int colMin = max(0, j-k), colMax = min(n-1, j+k);
                ans[i][j] = sum[rowMax+1][colMax+1] - sum[rowMin][colMax+1] - sum[rowMax+1][colMin] + sum[rowMin][colMin];
            }
        }
        return ans;
    }
};
// @lc code=end

