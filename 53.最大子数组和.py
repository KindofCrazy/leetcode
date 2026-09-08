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
        prefix, prefix_min, ans = 0, 0, float('-inf')
        for n in nums:
            prefix += n
            ans = max(ans, prefix- prefix_min)
            prefix_min = min(prefix_min, prefix)
        return ans

# @lc code=end

