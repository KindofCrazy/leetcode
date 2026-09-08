#
# @lc app=leetcode.cn id=560 lang=python
#
# [560] 和为 K 的子数组
#

# @lc code=start
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        prefix, ans = 0, 0
        prefix_count = {0: 1}
        for n in nums:
            prefix += n
            if prefix - k in prefix_count:
                ans += prefix_count[prefix - k]

            prefix_count[prefix] = prefix_count.get(prefix, 0) + 1
        return ans

# @lc code=end

