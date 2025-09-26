/*
 * @lc app=leetcode.cn id=2471 lang=cpp
 *
 * [2471] 逐层排序二叉树所需的最少操作数目
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

    /* TODO: 置换环 */
    int op(vector<int> arr) {
        auto nums = arr;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] != nums[i]) {
                int correctIdx = mp[nums[i]];  // nums[i] 位置
                swap(arr[i], arr[correctIdx]);
                mp[arr[correctIdx]] = correctIdx;
                mp[arr[i]] = i;
                res++;
            }
        }

        return res;
    }


    int minimumOperations(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans += op(level);
        }

        return ans;
    }
};
// @lc code=end

