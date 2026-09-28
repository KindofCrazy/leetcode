#
# @lc app=leetcode.cn id=19 lang=python
#
# [19] 删除链表的倒数第 N 个结点
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        first = head
        dummy = ListNode(0, head)
        second = dummy

        while n > 0:
            first = first.next
            n -= 1

        while first:
            first = first.next
            second = second.next

        prev = second
        prev.next = prev.next.next

        return dummy.next


# @lc code=end
