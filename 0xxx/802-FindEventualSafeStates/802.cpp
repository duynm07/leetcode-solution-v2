#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> indegree(n, 0), outdegree(n, 0);
        unordered_map<int, vector<int>> adjs;

        for (int u = 0; u < n; u++) {
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                if (adjs.count(v) == 0)
                    adjs[v] = {};
                adjs[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> S;
        for (int u = 0; u < n; u++)
            if (indegree[u] == 0)
                S.push(u);

        vector<int> ans;
        while (!S.empty()) {
            int u = S.front();
            S.pop();

            ans.push_back(u);

            if (adjs.count(u) == 0)
                continue;

            for (int v : adjs[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    S.push(v);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}