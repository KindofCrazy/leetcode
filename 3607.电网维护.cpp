/*
 * @lc app=leetcode.cn id=3607 lang=cpp
 *
 * [3607] 电网维护
 */

// @lc code=start
class Vertex {
    public:
        int heapId = -1;
        bool offline = false;
        int id = -1;

        Vertex() = default;                      
        Vertex(int idx): heapId(-1), offline(false), id(idx){}; 
};

using heap = priority_queue<int, vector<int>, greater<int>>;

class Solution {
public:
    vector<Vertex> vertices;
    vector<vector<int>> graph;
    vector<heap> heaps;

    void dfs(Vertex& v, int heapId, heap& h) {
        v.heapId = heapId;
        h.push(v.id);
        
        for (auto& vid: graph[v.id]) {
            auto& u = vertices[vid];
            if (u.heapId == -1) {
                dfs(u, heapId, h);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vertices.resize(c+1);
        graph.resize(c+1);

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& conn: connections) {
            graph[conn.at(0)].push_back(conn.at(1));
            graph[conn.at(1)].push_back(conn.at(0));
        }

        for (int i = 1, heapId = 0; i <= c; i++) {
            auto& v = vertices[i];
            if (v.heapId == -1) {
                heap h;
                dfs(v, heapId, h);
                heapId++;

                heaps.emplace_back(h);
            }
        }

        vector<int> ans;
        for (auto& query: queries) {
            int op = query.at(0), x = query.at(1);
            auto& v = vertices[x];

            if (op == 1) {
                if (!v.offline) {
                    ans.push_back(v.id);
                } else {
                    heap& h = heaps[v.heapId];
                    while (!h.empty() && vertices[h.top()].offline) {
                        h.pop();
                    }

                    if (!h.empty()) {
                        ans.push_back(h.top());
                    } else {
                        ans.push_back(-1);
                    }
                }
            } else if (op == 2) {
                v.offline = true;
            }
        }

        return ans;
    }
};
// @lc code=end

