#
# @lc app=leetcode.cn id=2 lang=python
#
# [2] 两数相加
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        carry = 0
        dummy = ListNode(0, None)
        prev = dummy
        p1, p2 = l1, l2
        while p1 or p2 or carry:
            sum = (p1.val if p1 else 0) + (p2.val if p2 else 0) + carry
            carry = sum // 10
            sum = sum % 10

            prev.next = ListNode(sum, None)

            p1 = p1.next if p1 else None
            p2 = p2.next if p2 else None
            prev = prev.next

        return dummy.next


# @lc code=end
