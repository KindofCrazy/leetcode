/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count = 0;
    
public:
    UnionFind(vector<vector<char>> &grid) {
        count = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i*n+j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unit(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        if (row > rows-1 || row < 0 || col < 0 || col > cols-1) {
            return;
        }
        if (grid[row][col] == '0') {
            return;
        }
        if (visited[row][col] == true) {
            return;
        }
        visited[row][col] = true;

        dfs(grid, visited, row+1, col);
        dfs(grid, visited, row-1, col);
        dfs(grid, visited, row, col+1);
        dfs(grid, visited, row, col-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r-1 >= 0 && grid[r-1][c] == '1') uf.unit(r*nc+c, (r-1)*nc+c);
                    if (r+1 < nr && grid[r+1][c] == '1') uf.unit(r*nc+c, (r+1)*nc+c);
                    if (c-1 >= 0 && grid[r][c-1] == '1') uf.unit(r*nc+c, r*nc + c -1);
                    if (c+1 < nc && grid[r][c+1] == '1') uf.unit(r*nc+c, r*nc+c+1);
                }
            }
        }

        return uf.getCount();
    }
};
// @lc code=end

