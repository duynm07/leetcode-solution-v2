#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adjs;
    int n;

    Graph(int n, vector<vector<int>> &edges) {
        this->n = n;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int c = edges[i][2];
            adjs[u].push_back({v, c});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int c = edge[2];
        adjs[u].push_back({v, c});
    }

    int shortestPath(int node1, int node2) {
        vector<bool> free(n, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, node1});

        while (true) {
            while (!pq.empty() && !free[pq.top().second])
                pq.pop();

            if (pq.empty())
                break;

            int u = pq.top().second;
            int du = pq.top().first;

            if (u == node2)
                return du;

            free[u] = false;
            pq.pop();

            for (pair<int, int> edge : adjs[u]) {
                int v = edge.first;
                int c = edge.second;
                pq.push({du + c, v});
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}