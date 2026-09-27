#
# @lc app=leetcode.cn id=11 lang=python
#
# [11] 盛最多水的容器
#


# @lc code=start
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        def capacity(height, left, right):
            return (right - left) * min(height[left], height[right])

        left, right = 0, len(height) - 1

        ans = 0
        while left < right:
            ans = max(ans, capacity(height, left, right))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return ans


# @lc code=end
