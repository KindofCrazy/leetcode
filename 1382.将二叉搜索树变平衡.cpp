/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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

    void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* create(int l, int r) {
        if (l > r) return nullptr;
        
        int mid = l + ((r - l) >> 1);
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = create(l, mid-1);
        root->right = create(mid+1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return create(0, arr.size()-1);
    }
};
// @lc code=end

