#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0), onesCol(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - (m + n);

        return grid;
    }
};

int main() {
    vector<vector<int>> nums = {{1}, {1}, {0}, {1}, {0}};
    Solution sol = Solution();
}