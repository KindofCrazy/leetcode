/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 *
 * [2904] 最短且字典序最小的美丽子字符串
 */

// @lc code=start
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int len = INT_MAX, oneCount = 0;
        string subString = "";
        for (int left = 0, right = 0; left < n; left++) {
            right = max(left, right);
            while (right < n && oneCount < k) {
                oneCount += (s[right++] == '1');
            }

            if (oneCount < k) {
                break;
            }
            int tmpLen = right - left;
            string tmpSubString = s.substr(left, tmpLen);
            if (tmpLen < len) {
                subString = tmpSubString;
                len = tmpLen;
            } else if (tmpLen == len) {
                if (subString > tmpSubString) {
                    subString = tmpSubString;
                }
            }

            if (right > left) oneCount -= (s[left] == '1');
        }

        return subString;
    }
};
// @lc code=end

