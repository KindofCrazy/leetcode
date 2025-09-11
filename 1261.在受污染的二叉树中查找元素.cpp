/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    TreeNode* rt;

    void recover(TreeNode* root) {
        if (!root) return;
        if (root->left) root->left->val = 2*root->val + 1;
        if (root->right) root->right->val = 2*root->val + 2;
        recover(root->left);
        recover(root->right);
    }

    FindElements(TreeNode* root) {
        rt = root;
        root->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        return f(target, rt);
    }

    bool f(int target, TreeNode* root) {
        if (!root) return false;
        if (root->val == target) return true;
        return f(target, root->left) || f(target, root->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

