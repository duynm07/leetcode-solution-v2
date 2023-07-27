#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries) {
        vector<bool> row(n, true);
        vector<bool> col(n, true);

        int remainRow = n;
        int remainCol = n;

        long long ans = 0;

        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int value = queries[i][2];

            if (type == 0 and row[index]) {
                row[index] = false;
                ans += remainCol * value;
                remainRow--;
            }

            if (type == 1 and col[index]) {
                col[index] = false;
                ans += remainRow * value;
                remainCol--;
            }
        }

        return ans;
    };
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> queries = {{0, 0, 1}, {1, 2, 2}, {0, 2, 3}, {1, 0, 4}};

    long long ans = solution.matrixSumQueries(3, queries);

    cout << ans;
}