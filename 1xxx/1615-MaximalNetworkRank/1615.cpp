#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<bool>> f(n, vector<bool>(n, false));
        vector<int> degree(n, 0);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            f[u][v] = true;
            f[v][u] = true;
            degree[u]++;
            degree[v]++;
        }

        int ans = 0;
        for (int u = 0; u < n - 1; u++) {
            for (int v = u + 1; v < n; v++) {
                ans = max(ans, degree[u] + degree[v] - f[u][v]);
            }
        }

        return ans;
    }
};