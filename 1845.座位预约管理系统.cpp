/*
 * @lc app=leetcode.cn id=1845 lang=cpp
 *
 * [1845] 座位预约管理系统
 */

// @lc code=start
class SeatManager {
public:
    int seats = 0; 
    priority_queue<int, vector<int>, greater<int>> available;

    SeatManager(int n) {
    }
    
    int reserve() {
        if (!available.empty()) {
            int x = available.top();
            available.pop();
            return x;
        }
        return ++seats;
    }
    
    void unreserve(int seatNumber) {
        available.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end

