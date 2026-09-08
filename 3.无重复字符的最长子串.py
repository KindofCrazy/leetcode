#
# @lc app=leetcode.cn id=3 lang=python
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        count = {}
        left, right, ans = 0, 0, 0
        while right < n:
            c = s[right]
            count[c] = count.get(c, 0) + 1

            while count[c] > 1:
                count[s[left]] -= 1
                left += 1

            right += 1
            ans = max(ans, right - left)
        return ans
# @lc code=end

