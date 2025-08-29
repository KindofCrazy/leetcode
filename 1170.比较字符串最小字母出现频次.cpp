/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lc code=start
class Solution {
public:
    int f(string s) {
        int count = 0;
        char smallest = s[0];
        for (char c: s) {
            if(c < smallest) {
                count = 1;
                smallest = c;
            } else if (c == smallest) {
                count++;
            }
        }

        return count;
    } 

    int binarySearch(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    return left;
}

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> queryFreq, wordFreq;
        for (string s: queries) {
            queryFreq.push_back(f(s));
        }
        for (string s: words) {
            wordFreq.push_back(f(s));
        }

        sort(wordFreq.begin(), wordFreq.end());

        vector<int> ans;
        for (int target: queryFreq) {
            int pos = binarySearch(wordFreq, target+1);
            ans.push_back(words.size() - pos);
        }

        return ans;
    }
};
// @lc code=end

