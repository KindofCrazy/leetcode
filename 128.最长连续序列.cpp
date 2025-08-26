/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n: nums) {
            s.insert(n);
        }

        int ans = 0;
        for(int n: s) {
            if (s.count(n-1)) {
                continue;
            }

            int length = 0;
            while(s.count(n)) {
                n++;
                length++;
                ans = max(ans, length);
            }
        }

        return ans;
    }
};
// @lc code=end

