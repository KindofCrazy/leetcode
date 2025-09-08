/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    vector<int> merge(vector<int>& arr1, vector<int> arr2) {
        vector<int> ans;
        int l1 = arr1.size(), l2 = arr2.size(), i = 0, j = 0;
        while (i < l1 && j < l2) {
            if (arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < l1) {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < l2) {
            ans.push_back(arr2[j]);
            j++;
        }

        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        inOrder(root1, arr1);
        inOrder(root2, arr2);
        return merge(arr1, arr2);
    }
};
// @lc code=end

