/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    void dfs(int i) {
        visited[i] = 1;
        for (int j: edges[i]) {
            if (visited[j] == 0) {
                dfs(j);
                if (!valid) {
                    return;
                }
            } else if (visited[j] == 1) {
                valid = false;
                return;
            }
        }

        visited[i] = 2;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses, 0);

        for (auto& info: prerequisites) {
            edges[info[0]].push_back(info[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] != 2 && valid) dfs(i);
        }

        return valid;
    }
};
// @lc code=end

