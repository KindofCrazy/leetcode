#
# @lc app=leetcode.cn id=206 lang=python
#
# [206] 反转链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        prev, cur = None, head

        while cur:
            nxt = cur.next
            cur.next = prev

            prev = cur
            cur = nxt

        return prev


# @lc code=end
