/*
 * @lc app=leetcode.cn id=3361 lang=cpp
 *
 * [3361] 两个字符串的切换距离
 */

// @lc code=start
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<long long> nextSum(2*26+1), preSum(2*26+1);
        for (int i = 0; i < 2*26; i++) {
            nextSum[i+1] = nextSum[i] + nextCost[i%26];
            preSum[i+1] = preSum[i] + previousCost[i%26];
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a', y = t[i] - 'a';
            if (x < y) {
                ans += min(nextSum[y] - nextSum[x], preSum[x+26+1] - preSum[y+1]);
            } else {
                ans += min(nextSum[y+26] - nextSum[x], preSum[x+1]- preSum[y+1]);
            }
        }

        return ans;
    }
};
// @lc code=end

