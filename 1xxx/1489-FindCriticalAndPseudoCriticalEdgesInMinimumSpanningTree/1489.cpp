#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    struct Edge {
        int u, v, w;
        int idx;
        Edge(int index, int i, int j, int c) : idx(index), u(i), v(j), w(c) {}
        Edge(int i, int j, int c) : u(i), v(j), w(c) {}
        // Comparison operator for Edge objects
        bool operator<(const Edge &other) const {
            return w > other.w; // Using greater-than for min-heap
        }
    };

    int findRoot(vector<int> &parent, int x) {
        while (x != parent[x])
            x = parent[x];
        return x;
    }

    int calculateMSTWeight(int n, vector<vector<int>> &edges, int forceEdgeIndex, int ignoreIndex) {
        // Create a min heap of edges
        priority_queue<Edge> pqEdges;
        for (int i = 0; i < edges.size(); i++) {
            if (i != forceEdgeIndex && i != ignoreIndex)
                pqEdges.push(Edge(i, edges[i][0], edges[i][1], edges[i][2]));
        }

        // Calculate the weight of MST
        int mstSize = 0;
        int mstWeight = 0;

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        if (forceEdgeIndex >= 0) {
            int u = edges[forceEdgeIndex][0];
            int v = edges[forceEdgeIndex][1];
            mstWeight += edges[forceEdgeIndex][2];
            mstSize++;
            parent[u] = v;
        }

        while (!pqEdges.empty() && mstSize < n - 1) {
            Edge edge = pqEdges.top();
            pqEdges.pop();

            int u = edge.u;
            int v = edge.v;

            int rootU = findRoot(parent, u);
            int rootV = findRoot(parent, v);
            if (rootU == rootV)
                continue;

            mstWeight += edge.w;
            mstSize++;
            parent[rootU] = rootV;
        }

        return mstSize == n - 1 ? mstWeight : -1;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        int orgMSTWeight = calculateMSTWeight(n, edges, -1, -1);
        vector<vector<int>> ans = {{}, {}};

        for (int i = 0; i < edges.size(); i++) {
            int ignoreMSTWeight = calculateMSTWeight(n, edges, -1, i);
            if (ignoreMSTWeight > orgMSTWeight || ignoreMSTWeight < 0) {
                ans[0].push_back(i);
            } else {
                int forceMSTWeight = calculateMSTWeight(n, edges, i, -1);
                if (forceMSTWeight == orgMSTWeight)
                    ans[1].push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}, {2, 3, 4}, {3, 4, 2}, {3, 5, 2}, {4, 5, 2}};
    vector<vector<int>> ans = sol.findCriticalAndPseudoCriticalEdges(6, edges);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}