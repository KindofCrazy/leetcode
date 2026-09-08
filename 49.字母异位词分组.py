#
# @lc app=leetcode.cn id=49 lang=python
#
# [49] 字母异位词分组
#

# @lc code=start
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hashmap = {}
        for s in strs:
            key = tuple(sorted(s))
            if key in hashmap:
                hashmap[key].append(s)
            else:
                hashmap[key] = [s]

        return hashmap.values()
# @lc code=end

