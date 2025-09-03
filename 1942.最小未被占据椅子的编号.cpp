/*
 * @lc app=leetcode.cn id=1942 lang=cpp
 *
 * [1942] 最小未被占据椅子的编号
 */

// @lc code=start
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> arrivals, leavings;
        for (int i = 0; i < n; i++) {
            arrivals.push_back({times[i][0], i});
            leavings.push_back({times[i][1], i});
        }
        sort(arrivals.begin(), arrivals.end());
        sort(leavings.begin(), leavings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        int leavingIdx = 0;
        unordered_map<int, int> seats;
        for (auto [arrival, person]: arrivals) {
            while (leavings[leavingIdx].first <= arrival) {
                available.push(seats[leavings[leavingIdx].second]);
                seats.erase(leavings[leavingIdx].second);
                leavingIdx++;
            }

            int s = available.top();
            available.pop();
            seats[person] = s;
            if (person == targetFriend) {
                return s;
            }
        }

        return 0;
    }
};
// @lc code=end

