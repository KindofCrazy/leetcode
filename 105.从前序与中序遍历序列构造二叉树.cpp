/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> idx;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if (prel > prer || inl > inr) return nullptr;

        TreeNode* root = new TreeNode(preorder[prel]);
        int index = idx[preorder[prel]];
        root->left = build(preorder, inorder, prel+1, prer, inl, index-1);
        root->right = build(preorder, inorder, prel+index-inl+1, prer, index+1, inr);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idx[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
// @lc code=end

