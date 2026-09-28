#
# @lc app=leetcode.cn id=48 lang=python
#
# [48] 旋转图像
#


# @lc code=start
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        top, bottom, left, right = 0, n - 1, 0, n - 1

        while top < bottom and left < right:
            for i in range(right - left):
                temp = matrix[top][left + i]
                matrix[top][left + i] = matrix[bottom - i][left]
                matrix[bottom - i][left] = matrix[bottom][right - i]
                matrix[bottom][right - i] = matrix[top + i][right]
                matrix[top + i][right] = temp

            left += 1
            right -= 1
            top += 1
            bottom -= 1


# @lc code=end
