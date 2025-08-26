/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        long long ans = 0, total = 0;
        for (int i = 0; i < n; i++) {
            total += customers[i] * !grumpy[i];
        }

        long long increase = 0, maxIncrease = 0;
        for (int i = 0; i < minutes-1; i++) {
            increase += grumpy[i] * customers[i];
        }
        for (int left = 0, right = minutes-1; right < n; left++, right++) {
            increase += grumpy[right] * customers[right];
            maxIncrease = max(increase, maxIncrease);
            increase -= grumpy[left] * customers[left];
        }

        return total + maxIncrease;
    }
};
// @lc code=end

