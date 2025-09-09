/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inl, int inr, int posl, int posr) {
        if (inl > inr || posl > posr) return nullptr;

        TreeNode* root = new TreeNode(postorder[posr]);
        int index = idx[postorder[posr]];
        root->left = build(inorder, postorder, inl, index-1, posl, posl+index-inl-1);
        root->right = build(inorder, postorder, index+1, inr, posl+index-inl, posr-1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idx[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
// @lc code=end

