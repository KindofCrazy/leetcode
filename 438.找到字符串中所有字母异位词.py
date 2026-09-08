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

        slen, plen = len(s), len(p)
        if plen > slen:
            return []

        ans = []
        for right in range(slen):
            scount[s[right]] = scount.get(s[right], 0) + 1

            if right >= plen:
                c = s[right-plen]
                scount[c] -= 1
                if scount[c] == 0:
                    del scount[c]

            if scount == pcount:
                ans.append(right-plen+1)

        return ans
# @lc code=end

