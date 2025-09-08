/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

    int base = 0, cnt = 0, maxcnt = 0;
    vector<int> ans;

    void update(int x) {
        if (x != base) {
            base = x;
            cnt = 0;
        }

        cnt++;
        if (cnt == maxcnt) {
            ans.push_back(base);
        }
        if (cnt > maxcnt) {
            maxcnt = cnt;
            ans = vector<int> {base};
        }
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

