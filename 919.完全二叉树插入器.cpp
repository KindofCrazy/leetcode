/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
public:
    TreeNode* CBTRoot;

    CBTInserter(TreeNode* root) {
        CBTRoot = root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(CBTRoot);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                else {
                    node->left = new TreeNode(val);
                    return node->val;
                }

                if (node->right) {
                    q.push(node->right);
                } else {
                    node->right = new TreeNode(val);
                    return node->val;
                }
            }
        }

        return 0;
    }
    
    TreeNode* get_root() {
        return CBTRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

