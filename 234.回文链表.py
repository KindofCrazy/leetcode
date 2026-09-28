#
# @lc app=leetcode.cn id=234 lang=python
#
# [234] 回文链表
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        if not head or not head.next:
            return True
        slow, fast = head, head
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        half_end = slow
        half_end.next = self.reverse(half_end.next)

        pa, pb = head, half_end.next
        while pa and pb:
            if pa.val != pb.val:
                return False
            pa = pa.next
            pb = pb.next

        half_end.next = self.reverse(half_end.next)
        return True

    def reverse(self, head):
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
