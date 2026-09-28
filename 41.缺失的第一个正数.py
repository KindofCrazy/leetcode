#
# @lc app=leetcode.cn id=41 lang=python
#
# [41] 缺失的第一个正数
#


# @lc code=start
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = len(nums) + 1
        for i in range(len(nums)):
            if nums[i] <= 0 or nums[i] > len(nums):
                nums[i] = len(nums) + 1
        for i in range(len(nums)):
            n = abs(nums[i])
            if 1 <= n <= len(nums):
                nums[n - 1] = -abs(nums[n - 1])

        for i in range(len(nums)):
            if nums[i] > 0:
                return i + 1
        return ans


# @lc code=end
