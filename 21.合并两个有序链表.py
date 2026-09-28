#
# @lc app=leetcode.cn id=21 lang=python
#
# [21] 合并两个有序链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        p1, p2 = list1, list2

        dummy = ListNode(0, None)
        prev = dummy
        while p1 and p2:
            if p1.val < p2.val:
                prev.next = p1
                p1 = p1.next
                prev = prev.next
            else:
                prev.next = p2
                p2 = p2.next
                prev = prev.next

        while p1:
            prev.next = p1
            p1 = p1.next
            prev = prev.next

        while p2:
            prev.next = p2
            p2 = p2.next
            prev = prev.next

        return dummy.next


# @lc code=end
