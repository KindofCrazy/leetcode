/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        int length = getLength(head);
        int step = length - n;

        while(step > 0) {
            pre = pre->next;
            step--;
        }

        pre->next = pre->next->next;
        return dummy->next;
    }

    int getLength(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }
};
// @lc code=end

