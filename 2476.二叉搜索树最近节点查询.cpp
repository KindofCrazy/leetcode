/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> arr;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }    

    int binarySearch(int query) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] >= query) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);

        vector<vector<int>> ans;
        for (int query: queries) {
            int idx = binarySearch(query);
            int minval = -1, maxval = -1;
            if (idx < arr.size()) maxval = arr[idx];
            if (idx < arr.size() && arr[idx] == query) minval = arr[idx];
            else if (idx >= 1) minval = arr[idx-1];
            ans.push_back({minval, maxval});
        }
        return ans;
    }
};
// @lc code=end

