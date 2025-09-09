/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 *
 * [2196] 根据描述创建二叉树
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> cnt;
        for (auto des: descriptions) {
            int parent = des[0], child = des[1], isLeft = des[2];
            if (!mp.count(parent)) {
                mp[parent] = new TreeNode(parent);
            }
            if (!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }

            TreeNode* pa = mp[parent],*ch = mp[child];
            if (isLeft) {
                pa->left = ch;
            } else {
                pa->right = ch;
            }

            if (!cnt.count(parent)) cnt[parent] = 0;
            cnt[child]++;
        }

        TreeNode* root = nullptr;
        for (auto [n, c]: cnt) {
            if (c == 0) {
                root = mp[n];
            }
        }

        return root;
    }
};
// @lc code=end

