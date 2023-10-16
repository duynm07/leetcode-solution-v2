#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> adjs(vector<vector<int>> &a) {
        vector<vector<vector<int>>> ans;
        int imax = 0;
        int jmax = 0;
        int m = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] > m) {
                    m = a[i][j];
                    imax = i;
                    jmax = j;
                }
            }
        }
        if (imax < 2) {
            vector<vector<int>> temp = a;
            temp[imax][jmax]--;
            temp[imax + 1][jmax]++;
            ans.push_back(temp);
        }
        if (jmax < 2) {
            vector<vector<int>> temp = a;
            temp[imax][jmax]--;
            temp[imax][jmax + 1]++;
            ans.push_back(temp);
        }
        if (imax > 0) {
            vector<vector<int>> temp = a;
            temp[imax][jmax]--;
            temp[imax - 1][jmax]++;
            ans.push_back(temp);
        }
        if (jmax > 0) {
            vector<vector<int>> temp = a;
            temp[imax][jmax]--;
            temp[imax][jmax - 1]++;
            ans.push_back(temp);
        }
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         if (a[i][j] > 0) {
        //             if (i < 2) {
        //                 vector<vector<int>> temp = a;
        //                 temp[i][j]--;
        //                 temp[i + 1][j]++;
        //                 ans.push_back(temp);
        //             }
        //             if (j < 2) {
        //                 vector<vector<int>> temp = a;
        //                 temp[i][j]--;
        //                 temp[i][j + 1]++;
        //                 ans.push_back(temp);
        //             }
        //             if (i > 0) {
        //                 vector<vector<int>> temp = a;
        //                 temp[i][j]--;
        //                 temp[i - 1][j]++;
        //                 ans.push_back(temp);
        //             }
        //             if (j > 0) {
        //                 vector<vector<int>> temp = a;
        //                 temp[i][j]--;
        //                 temp[i][j - 1]++;
        //                 ans.push_back(temp);
        //             }
        //         }
        //     }
        // }
        return ans;
    }

    string grid2string(vector<vector<int>> &grid) {
        string s = "";
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                s = s + (char)(grid[i][j] + '0');
            }
        }
        return s;
    }

    int minimumMoves(vector<vector<int>> &grid) {
        unordered_map<string, int> f;
        queue<vector<vector<int>>> q;

        q.push(grid);
        f[grid2string(grid)] = 0;

        vector<int> mx = {1, -1, 0, 0};
        vector<int> my = {0, 0, 1, -1};

        while (true) {
            vector<vector<int>> curr = q.front();
            q.pop();

            string scurr = grid2string(curr);

            for (vector<vector<int>> adj : adjs(curr)) {
                string s = grid2string(adj);
                if (f.count(s) > 0)
                    continue;
                f[s] = f[scurr] + 1;
                if (s == "111111111")
                    return f[s];
                q.push(adj);
            }
        }

        return f["111111111"];
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> grid = {{0, 0, 3}, {0, 2, 0}, {1, 3, 0}};
    cout << sol.minimumMoves(grid);
}