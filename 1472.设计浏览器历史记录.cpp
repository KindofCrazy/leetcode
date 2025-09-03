/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */

// @lc code=start
class BrowserHistory {
public:
    vector<string> history;
    int maxIndex = 0;
    int curIndex = 0;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        maxIndex = 0;
        curIndex = 0;
    }
    
    void visit(string url) {
        if (curIndex == history.size() - 1) {
            history.push_back(url);
            curIndex++;
            maxIndex++;
        } else {
            history[++curIndex] = url;
            maxIndex = curIndex;
        }
    }
    
    string back(int steps) {
        curIndex = max(0, curIndex - steps);
        return history[curIndex];
    }
    
    string forward(int steps) {
        curIndex = min(maxIndex, curIndex + steps);
        return history[curIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

