/*
 * @lc app=leetcode.cn id=3542 lang=cpp
 *
 * [3542] 将所有元素变为 0 的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stk;
        int ans = 0;
        for (int n: nums) {
            while (!stk.empty() && stk.top() > n) {
                stk.pop();
                ans++;
            }
            if (n == 0) continue;
            if (stk.empty() || stk.top() < n) {
                stk.push(n);
            }
        }

        ans += stk.size();

        return ans;
    }
};
// @lc code=end

