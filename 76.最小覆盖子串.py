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

        slen, tlen = len(s), len(t)
        scount, tcount = {}, {}
        for c in t:
            tcount[c] = tcount.get(c, 0) + 1

        def check():
            for c in tcount:
                if scount.get(c, 0) < tcount[c]:
                    return False
            return True

        ans = ""
        left = 0
        for right in range(slen):
            right_c = s[right]
            scount[right_c] = scount.get(right_c, 0) + 1

            while check():
                substr = s[left:right+1]
                if ans == "" or len(substr) < len(ans):
                    ans = substr
                
                scount[s[left]] -= 1
                left += 1

        return ans



# @lc code=end

