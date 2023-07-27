#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {

        vector<vector<int>> adjs(n);

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            adjs[u].push_back(i);
            adjs[v].push_back(i);
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        vector<double> d(n, 0);

        d[start] = 1;
        pq.push(make_pair(1, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            double du = pq.top().first;
            pq.pop();

            if (du < d[u]) {
                continue;
            }

            for (int i : adjs[u]) {
                vector<int> edge = edges[i];
                int v = edge[0] + edge[1] - u;
                if (d[u] * succProb[i] > d[v]) {
                    d[v] = d[u] * succProb[i];
                    pq.push(make_pair(d[u] * succProb[i], v));
                }
            }
        }

        return d[end];
    }
};