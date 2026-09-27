#
# @lc app=leetcode.cn id=438 lang=python
#
# [438] 找到字符串中所有字母异位词
#


# @lc code=start
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        scount, pcount = {}, {}
        for c in p:
            pcount[c] = pcount.get(c, 0) + 1

        ans = []

        for right in range(len(s)):
            c = s[right]
            scount[c] = scount.get(c, 0) + 1

            if right >= len(p):
                scount[s[right - len(p)]] -= 1
                if scount[s[right - len(p)]] == 0:
                    del scount[s[right - len(p)]]

            if scount == pcount:
                ans.append(right - len(p) + 1)

        return ans


# @lc code=end
