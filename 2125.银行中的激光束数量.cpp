/*
 * @lc app=leetcode.cn id=2125 lang=cpp
 *
 * [2125] 银行中的激光束数量
 */

// @lc code=start
class Solution {
public:
    int oneCount(string s) {
        int cnt = 0;
        for (char c: s) {
            cnt += (c == '1');
        }

        return cnt;
    }

    int numberOfBeams(vector<string>& bank) {
        int pre = 0, ans = 0;
        for (string s: bank) {
            int cnt = oneCount(s);
            if (!cnt) {
                continue;
            }

            ans += pre * cnt;
            pre = cnt;
        }

        return ans;
    }
};
// @lc code=end

