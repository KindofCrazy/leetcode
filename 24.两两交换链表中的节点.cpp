/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while(prev != nullptr && prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* nextPair = prev->next->next->next;
            ListNode* p1 = prev->next, *p2 = prev->next->next;
            p2->next = p1;
            p1->next = nextPair;
            prev->next = p2;
            prev = prev->next->next;
        }

        return dummy->next;
    }
};
// @lc code=end

