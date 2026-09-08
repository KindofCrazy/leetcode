#
# @lc app=leetcode.cn id=239 lang=python
#
# [239] 滑动窗口最大值
#

# @lc code=start
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        q = deque()
        ans = []

        for right in range(len(nums)):
            while q and nums[q[-1]] <= nums[right]:
                q.pop()

            q.append(right)

            while q[0] <= right - k:
                q.popleft()

            if right >= k-1:
                ans.append(nums[q[0]])

        return ans
# @lc code=end

