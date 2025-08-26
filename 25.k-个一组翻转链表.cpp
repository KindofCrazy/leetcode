/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;

        while(true) {
            ListNode* originalStart = prev->next;
            ListNode* originalEnd = prev;
            for (int i = 0; i < k; i++) {
                originalEnd = originalEnd->next;
                if (originalEnd== nullptr) return dummy->next;
            }
            
            ListNode *nextStart = originalEnd->next;
            prev->next = reverseKList(originalStart, k);
            originalStart->next = nextStart;
            prev = originalStart;
        }        
        return dummy->next;
    }

    ListNode* reverseKList(ListNode* head, int k) {
        ListNode* prev = nullptr, *cur = head;
        int count = 0;
        while(count < k && cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
        return prev;
    }
};
// @lc code=end

