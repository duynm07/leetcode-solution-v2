#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDay(int row, int col, int day, vector<vector<int>> dayBecomeWater) {
        vector<int> mx = {1, -1, 0, 0};
        vector<int> my = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        vector<vector<bool>> f(row + 1, vector<bool>(col + 1, true));

        for (int y = 1; y <= col; y++) {
            int x = 1;
            if (dayBecomeWater[x][y] <= day)
                continue;

            f[x][y] = false;
            q.push({x, y});
        }

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            if (u == row)
                return true;
            for (int i = 0; i < 4; i++) {
                int ui = u + mx[i];
                int vi = v + my[i];
                if (ui <= 0 || ui > row || vi <= 0 || vi > col)
                    continue;
                if (dayBecomeWater[ui][vi] > day && f[ui][vi]) {
                    f[ui][vi] = false;
                    q.push({ui, vi});
                }
            }
        }

        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        vector<vector<int>> dayBecomeWater(row + 1, vector<int>(col + 1));
        for (int i = 0; i < cells.size(); i++)
            dayBecomeWater[cells[i][0]][cells[i][1]] = i;

        int first = 1;
        int last = row * col;
        int ans = 0;
        while (first <= last) {
            int mid = (first + last) / 2;
            bool check = !checkDay(row, col, mid, dayBecomeWater);
            if (check) {
                ans = mid;
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }

        return ans;
    }
};