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
        for str in strs:
            key = tuple(sorted(str))
            if key in hashmap:
                hashmap[key].append(str)
            else:
                hashmap[key] = [str]

        return hashmap.values()


# @lc code=end
