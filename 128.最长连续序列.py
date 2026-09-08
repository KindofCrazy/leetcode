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
        for n in nums:
            if n - 1 in nums:
                continue
            length = 1
            while n + 1 in nums:
                length += 1
                n = n + 1
            ans = max(ans, length)

        return ans

# @lc code=end

