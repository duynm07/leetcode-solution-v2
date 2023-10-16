#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        vector<int> mx = {-1, 1, 0, 0};
        vector<int> my = {0, 0, 1, -1};

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> d(m, vector<int>(n, 1e6));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        d[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int eff = get<0>(pq.top());
            int ux = get<1>(pq.top());
            int uy = get<2>(pq.top());
            pq.pop();

            if (ux == m - 1 && uy == n - 1)
                break;

            for (int i = 0; i < 4; i++) {
                int vx = ux + mx[i];
                int vy = uy + my[i];
                if (vx < 0 || vx >= m || vy < 0 || vy >= n)
                    continue;

                int newEffort = max(eff, abs(heights[vx][vy] - heights[ux][uy]));
                if (newEffort < d[vx][vy]) {
                    d[vx][vy] = newEffort;
                    pq.push({newEffort, vx, vy});
                }
            }
        }

        return d[m - 1][n - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << sol.minimumEffortPath(heights);

    return 0;
}