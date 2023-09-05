#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    struct Edge {
        int u, v, w;
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

    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        priority_queue<Edge> edges;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                Edge edge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                edges.push(edge);
            }

        int MST = 0;
        int ans = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        while (MST < n - 1) {
            Edge edge = edges.top();
            edges.pop();

            int u = edge.u;
            int v = edge.v;

            int rootU = findRoot(parent, u);
            int rootV = findRoot(parent, v);
            if (rootU == rootV)
                continue;

            ans += edge.w;
            MST++;
            parent[rootU] = rootV;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << sol.minCostConnectPoints(points);
}