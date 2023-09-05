#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> flag(m, vector<bool>(n, true));
        vector<vector<int>> d(m, vector<int>(n, m * n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    flag[i][j] = false;
                    d[i][j] = 0;
                }
            }
        }

        vector<int> mx = {1, -1, 0, 0};
        vector<int> my = {0, 0, 1, -1};
        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ui = u + mx[i];
                int vi = v + my[i];
                if (ui < 0 || ui >= m || vi < 0 || vi >= m || mat[ui][vi] == 0)
                    continue;

                d[ui][vi] = mat[ui][vi] ? min(d[ui][vi], d[u][v] + 1) : 0;
                if (flag[ui][vi])
                    q.push({ui, vi});
                flag[ui][vi] = false;
            }
        }

        return d;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {{0}, {0}, {0}, {0}, {0}};
    vector<vector<int>> d = sol.updateMatrix(mat);
    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[0].size(); j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}