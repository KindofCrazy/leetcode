/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    int idx = 0;

    TreeNode* create(vector<int>& preorder, int mi, int mx) {
        if (idx >= preorder.size()) return nullptr;
        if (preorder[idx] < mi || preorder[idx] > mx) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = create(preorder, mi, root->val);
        root->right = create(preorder, root->val, mx);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder, INT_MIN, INT_MAX);
    }
};
// @lc code=end

