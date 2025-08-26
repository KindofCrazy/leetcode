/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *ptr = dummy;

        int carry = 0;
        while(p1 != nullptr || p2 != nullptr) {
            int val1 = p1 == nullptr ? 0: p1->val;
            int val2 = p2 == nullptr ? 0: p2->val;
            int sum = val1 + val2 + carry;
            if (sum >= 10) {
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ptr->next = new ListNode(sum);
            p1 = p1 == nullptr ? nullptr: p1->next;
            p2 = p2 == nullptr ? nullptr: p2->next;
            ptr = ptr->next;
        }

        if (carry == 1) {
            ptr->next = new ListNode(1);
        }
        return dummy->next;
    }
};
// @lc code=end

