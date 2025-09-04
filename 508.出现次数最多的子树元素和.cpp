/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) return 0;

        int left = dfs(root->left, mp), right = dfs(root->right, mp);
        int sum = root->val + left + right;
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        dfs(root, mp);

        int mx = 0;
        for (auto& [sum, cnt]: mp) {
            mx = max(mx, cnt);
        }

        vector<int> ans;
        for (auto& [sum, cnt]: mp) {
            if (cnt == mx) ans.push_back(sum);
        }

        return ans;
    }
};
// @lc code=end

