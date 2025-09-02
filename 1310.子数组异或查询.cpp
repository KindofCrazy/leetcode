/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> s(n+1);
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] ^ arr[i];
        }

        vector<int> ans;
        for (auto query: queries) {
            ans.push_back(s[query[1]+1] ^ s[query[0]]);
        }

        return ans;
    }
};
// @lc code=end

