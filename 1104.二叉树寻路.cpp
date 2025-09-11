/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution {
public:
    int getReverse(int label, int row) {
        return pow(2, row-1) + pow(2, row) - 1 - label;
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int row = 0, rowStart = 1;
        while (rowStart <= label) {
            row++;
            rowStart *= 2;
        }
        
        if (row % 2 == 0) {
            label = getReverse(label, row);
        }
        while (row > 0) {
            if (row % 2 == 0) {
                ans.push_back(getReverse(label, row));
            } else {
                ans.push_back(label);
            }
            row--;
            label /= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end

