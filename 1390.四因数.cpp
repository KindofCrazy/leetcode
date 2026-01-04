/*
 * @lc app=leetcode.cn id=1390 lang=cpp
 *
 * [1390] 四因数
 */

// @lc code=start
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n: nums) {
            int factor_sum = 0, factor_count = 0;
            for (int i = 1; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    factor_sum += i;

                    if (i * i == n) {
                        factor_count += 1;
                    } else {
                        factor_count += 2;
                        factor_sum += n / i;
                    }
                }
            }

            if (factor_count == 4) {
                ans += factor_sum;
            }
        }

        return ans;
    }
};
// @lc code=end

