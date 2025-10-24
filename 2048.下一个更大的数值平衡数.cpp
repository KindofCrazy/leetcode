/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start
class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (true) {
            n++;

            vector<int> cnt(10, 0);
            for (int x = n; x > 0; x /= 10) {
                cnt[x % 10]++;
            }

            bool flag = true;
            for (int x = n; x > 0; x /= 10) {
                if (cnt[x % 10] != x % 10) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                return n;
            }
        }
    }
};
// @lc code=end

