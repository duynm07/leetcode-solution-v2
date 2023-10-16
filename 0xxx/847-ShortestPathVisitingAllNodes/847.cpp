#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = 0;
        for (vector<int> edges : graph)
            n = max(n, *max_element(edges.begin(), edges.end()) + 1);

        if (n <= 2)
            return n - 1;

        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
        vector<vector<bool>> f(n, vector<bool>(1 << n, true));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            int stt = 0 | (1 << i);
            f[i][stt] = false;
            q.push({i, stt});
            dp[i][stt] = 0;
        }

        while (!q.empty()) {
            int u = q.front().first;
            int stt = q.front().second;
            q.pop();

            for (int v : graph[u]) {
                int newStt = stt | (1 << v);
                if (!f[v][newStt])
                    continue;
                f[v][newStt] = false;
                dp[v][newStt] = dp[u][stt] + 1;
                q.push({v, newStt});
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[i][(1 << n) - 1]);

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}