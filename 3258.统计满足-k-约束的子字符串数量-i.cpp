/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 */

// @lc code=start
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();

        int ans = 0, zeroCount = 0, oneCount = 0;
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n) {
                int newZeroCount = zeroCount + (s[right] == '0');
                int newOneCount = oneCount + (s[right] == '1');
                if (min(newOneCount, newZeroCount) <= k) {
                    right++;
                    zeroCount = newZeroCount;
                    oneCount = newOneCount;
                } else {
                    break;
                }
            }

            ans += (right - left);

            if (right > left) {
                zeroCount -= (s[left] == '0');
                oneCount -= (s[left] == '1');
            }
        }

        return ans;
    }
};
// @lc code=end

