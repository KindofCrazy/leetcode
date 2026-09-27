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

        for i, v in enumerate(nums):
            while q and q[-1][1] < v:
                q.pop()

            q.append([i, v])

            if i >= k - 1:
                while q[0][0] <= i - k:
                    q.popleft()
                ans.append(q[0][1])

        return ans


# @lc code=end
