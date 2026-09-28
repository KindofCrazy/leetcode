#
# @lc app=leetcode.cn id=160 lang=python
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None

        alen, blen = 0, 0
        pa, pb = headA, headB
        while pa:
            alen += 1
            pa = pa.next
        while pb:
            blen += 1
            pb = pb.next

        pa, pb = headA, headB
        for _ in range(alen - blen):
            pa = pa.next
        for _ in range(blen - alen):
            pb = pb.next

        while pa and pb:
            if pa == pb:
                return pa
            else:
                pa = pa.next
                pb = pb.next

        return None


# @lc code=end
