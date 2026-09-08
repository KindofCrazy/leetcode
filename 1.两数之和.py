#
# @lc app=leetcode.cn id=1 lang=python
#
# [1] 两数之和
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for (i, v) in enumerate(nums):
            if target - v in hashmap:
                return [hashmap[target - v], i]

            hashmap[v] = i
# @lc code=end

