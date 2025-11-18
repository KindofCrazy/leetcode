/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n-1) {
            if (bits[i] == 0) {
                i++;
            } else {
                i = i + 2;
            }
        }

        return i == n - 1;
    }
};
// @lc code=end

