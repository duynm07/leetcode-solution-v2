#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        queue<vector<int>> q;

        int m = grid.size();
        int n = grid[0].size();

        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    q.push({i, j, 0});
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                    k++;
            }
        }

        int target = (1 << k) - 1;
        vector<vector<vector<int>>> d(m, vector<vector<int>>(n, vector<int>(target + 1, -1)));
        d[q.front()[0]][q.front()[1]][q.front()[2]] = 0;

        vector<int> mx = {1, -1, 0, 0};
        vector<int> my = {0, 0, 1, -1};

        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int s = q.front()[2];
            q.pop();

            if (s == target) {
                return d[x][y][s];
            }

            for (int i = 0; i < 4; i++) {
                int xi = x + mx[i];
                int yi = y + my[i];
                if (xi < 0 || xi >= m || yi < 0 || yi >= n)
                    continue;
                if (grid[xi][yi] == '#')
                    continue;
                if (grid[xi][yi] >= 'A' && grid[xi][yi] <= 'Z' && (s & (1 << (grid[xi][yi] - 'A'))) == 0)
                    continue;
                int si = grid[xi][yi] >= 'a' && grid[xi][yi] <= 'z' ? s | (1 << (grid[xi][yi] - 'a')) : s;
                if (d[xi][yi][si] < 0) {
                    d[xi][yi][si] = d[x][y][s] + 1;
                    q.push({xi, yi, si});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> grid = {"@.a..", "###.#", "b.A.B"};
    // vector<string> grid = {"@..aA", "..B#.", "....b"};
    // vector<string> grid = {"@Aa"};
    int ans = sol.shortestPathAllKeys(grid);
    cout << ans;

    // int x = 0;
    // for (int i = 0; i < 6; i++) {
    //     int num = x | (1 << i);
    //     cout << num << " ";
    // }
}