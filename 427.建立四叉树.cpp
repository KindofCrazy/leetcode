/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int row1, int row2, int col1, int col2) {
        bool isTrue = true, isFalse = true;

        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                isTrue = isTrue && (grid[i][j] == 1);
                isFalse = isFalse && (grid[i][j] == 0);
            }
        }

        if (isTrue || isFalse) {
            return new Node(isTrue, true);
        }
        
        Node* node = new Node(true, false);
        int rowmid = (row1+row2) / 2, colmid = (col1+col2) / 2;;
        node->topLeft = create(grid, row1, rowmid, col1, colmid);
        node->topRight = create(grid, row1, rowmid, colmid+1, col2);
        node->bottomLeft = create(grid, rowmid+1, row2, col1, colmid);
        node->bottomRight = create(grid, rowmid+1, row2, colmid+1, col2);
    

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return create(grid, 0, m-1, 0, n-1);
    }
};
// @lc code=end

