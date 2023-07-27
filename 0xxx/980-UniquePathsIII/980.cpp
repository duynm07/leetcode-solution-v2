#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mx = {1, -1, 0, 0};
    vector<int> my = {0, 0, 1, -1};

    vector<vector<bool>> flag;
    vector<pair<int, int>> x;
    int ans = 0;

    void attemp(vector<vector<int>> &grid, int i, int k) {
        int u = x[i - 1].first;
        int v = x[i - 1].second;
        for (int j = 0; j < 4; j++) {
            int ui = u + mx[j];
            int vi = v + my[j];
            if (ui < 0 || ui >= grid.size() || vi < 0 || vi >= grid[ui].size())
                continue;
            if (!flag[ui][vi])
                continue;

            flag[ui][vi] = false;
            if (grid[ui][vi] == 0 || grid[ui][vi] == 2) {
                x[i].first = ui;
                x[i].second = vi;
                if (i == k - 1) {
                    if (grid[ui][vi] == 2)
                        ans++;
                } else
                    attemp(grid, i + 1, k);
            }
            flag[ui][vi] = true;
        }
    }

    int uniquePathsIII(vector<vector<int>> &grid) {
        int k = 2;
        int m = grid.size();
        int n = grid[0].size();

        flag.resize(m);
        for (int i = 0; i < m; i++) {
            flag[i].resize(n);
            for (int j = 0; j < n; j++) {
                flag[i][j] = true;
                if (grid[i][j] == 0)
                    k++;
            }
        }

        x.resize(k);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x[0].first = i;
                    x[0].second = j;
                    flag[i][j] = false;
                }
            }
        }

        attemp(grid, 1, k);

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};

    Solution solution = Solution();
    int ans = solution.uniquePathsIII(grid);

    cout << ans;

    return 0;
}