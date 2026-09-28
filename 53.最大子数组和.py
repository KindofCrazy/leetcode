#
# @lc app=leetcode.cn id=53 lang=python
#
# [53] 最大子数组和
#


# @lc code=start
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = 0
        prefixMin = 0
        ans = float("-inf")

        for n in nums:
            prefix += n
            ans = max(ans, prefix - prefixMin)
            prefixMin = min(prefixMin, prefix)

        return ans


# @lc code=end
