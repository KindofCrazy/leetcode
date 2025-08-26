/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* firstHalfEnd = halfEnd(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* p1 = head, *p2 = secondHalfStart;
        bool ans = true;
        while(p2 != nullptr) {
            if (p1->val != p2->val) ans = false;
            p1 = p1->next;
            p2 = p2->next;
        }

        firstHalfEnd->next = reverseList(secondHalfStart);
        return ans;
    }

    ListNode* halfEnd(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *prev = nullptr, *cur = head, *next = head->next;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};
// @lc code=end

