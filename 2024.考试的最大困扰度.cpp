/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int ans = 0, TCount = 0, FCount = 0;
        for (int left = 0, right = 0; right < n; left++) {
            while (right < n) {
                int newTCount = TCount + (answerKey[right] == 'T');
                int newFcount = FCount + (answerKey[right] == 'F');
                if (min(newTCount, newFcount) <= k) {
                    right++;
                    TCount = newTCount;
                    FCount = newFcount;
                } else {
                    break;
                }
            }

            ans = max(ans, right - left);
            TCount -= answerKey[left] == 'T';
            FCount -= answerKey[left] == 'F';
        }

        return ans;
    }
};
// @lc code=end

