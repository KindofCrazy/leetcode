#
# @lc app=leetcode.cn id=128 lang=python
#
# [128] 最长连续序列
#


# @lc code=start
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        ans = 0
        for num in nums:
            if num - 1 in nums:
                continue
            else:
                len = 0
                while num in nums:
                    ans = max(ans, len + 1)
                    len += 1
                    num += 1

        return ans


# @lc code=end
