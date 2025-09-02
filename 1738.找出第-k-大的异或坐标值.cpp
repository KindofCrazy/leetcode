/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i+1][j+1] = sum[i+1][j] ^ sum[i][j+1] ^ sum[i][j] ^ matrix[i][j];
                pq.push(sum[i+1][j+1]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
// @lc code=end

