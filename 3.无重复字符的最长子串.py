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
        value = dict()
        left, right = 0, 0
        ans = 0

        for right in range(len(s)):
            c = s[right]
            value[c] = value.get(c, 0) + 1

            while left < right and value[c] > 1:
                value[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

            right += 1
        return ans


# @lc code=end
