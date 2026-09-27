#
# @lc app=leetcode.cn id=76 lang=python
#
# [76] 最小覆盖子串
#


# @lc code=start
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        scount, tcount = {}, {}
        for c in t:
            tcount[c] = tcount.get(c, 0) + 1

        def check():
            for c in tcount:
                if scount.get(c, 0) < tcount[c]:
                    return False
            return True

        left = 0
        ans = ""
        for right in range(len(s)):
            c = s[right]
            scount[c] = scount.get(c, 0) + 1

            if right >= len(t) - 1:
                while check():
                    substr = s[left : right + 1]
                    if ans is "" or len(substr) < len(ans):
                        ans = substr
                    scount[s[left]] -= 1
                    left += 1

        return ans


# @lc code=end
