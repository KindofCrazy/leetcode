/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> occ;
        for (int n: nums) {
            occ.insert(n);
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy, *cur = head;

        while (cur) {
            ListNode* nxt = cur->next;
            if (occ.count(cur->val)) {
                pre->next = nxt;
            } else {
                pre = pre->next;
            }

            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

