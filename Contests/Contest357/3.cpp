#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>> &grid, vector<pair<int, int>> &thieves, int safenessFactor) {
        if (safenessFactor == 0)
            return true;

        int n = grid.size();

        for (int j = 0; j < thieves.size(); j++) {
            int xThief = thieves[j].first;
            int yThief = thieves[j].second;
            if (xThief + yThief < safenessFactor || abs(n - 1 - xThief) + abs(n - 1 - yThief) < safenessFactor)
                return false;
        }

        vector<vector<bool>> flag(n, vector<bool>(n, true));
        vector<int> px = {1, -1, 0, 0};
        vector<int> py = {0, 0, 1, -1};
        queue<pair<int, int>> q;

        int x = 0;
        int y = 0;

        q.push({x, y});

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            // cout << u << " " << v << endl;
            flag[u][v] = false;
            if (u == n - 1 && v == n - 1)
                return true;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ui = u + px[i];
                int vi = v + py[i];
                if (ui < 0 || ui >= n || vi < 0 || vi >= n || grid[ui][vi] == 1 || !flag[ui][vi])
                    continue;
                // cout << "    " << ui << " " << vi << endl;
                flag[ui][vi] = false;
                bool isSafe = true;
                for (int j = 0; j < thieves.size() && isSafe; j++) {
                    int xThief = thieves[j].first;
                    int yThief = thieves[j].second;
                    if (abs(ui - xThief) + abs(vi - yThief) < safenessFactor)
                        isSafe = false;
                }
                if (isSafe)
                    q.push({ui, vi});
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] + grid[n - 1][n - 1] > 0)
            return 0;

        vector<pair<int, int>> thieves;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    thieves.push_back({i, j});

        // return check(grid, thieves, 2);

        int first = 0;
        int last = 2 * n;
        int ans = -1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (check(grid, thieves, mid)) {
                ans = mid;
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    // vector<vector<int>> grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    // vector<vector<int>> grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    vector<vector<int>> grid = {{0, 1, 1}, {0, 0, 0}, {0, 0, 0}};
    cout << sol.maximumSafenessFactor(grid);
}