/*
 * @lc app=leetcode.cn id=2257 lang=cpp
 *
 * [2257] 统计网格图中没有被保卫的格子数
 */

// @lc code=start
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> seen(m, vector<int>(n, 0));

        // 0->not seen, 1->guard, 2->wall, 3->seen
        for (auto& pos: guards) {
            int x = pos[0], y = pos[1];
            seen[x][y] = 1;
        }
        for (auto& pos: walls) {
            int x = pos[0], y = pos[1];
            seen[x][y] = 2;
        }

        for (auto& pos: guards) {
            int x = pos[0], y = pos[1];

            for (int i = x-1; i >= 0; i--) {
                if (seen[i][y] == 1 || seen[i][y] == 2) {
                    break;
                }

                seen[i][y] = 3;
            }

            for (int i = x+1; i < m; i++) {
                if (seen[i][y] == 1 || seen[i][y] == 2) {
                    break;
                }

                seen[i][y] = 3;
            }

            for (int j = y-1; j >= 0; j--) {
                if (seen[x][j] == 1 || seen[x][j] == 2) {
                    break;
                }

                seen[x][j] = 3;
            }

            for (int j = y+1; j < n; j++) {
                if (seen[x][j] == 1 || seen[x][j] == 2) {
                    break;
                }

                seen[x][j] = 3;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seen[i][j] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

