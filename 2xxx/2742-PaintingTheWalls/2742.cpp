#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int i, int nWall, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp) {
        if (nWall <= 0)
            return 0;

        if (i == cost.size())
            return 1e9;

        return dp[i][nWall] = dp[i][nWall] >= 0 ? dp[i][nWall] : min(solve(i + 1, nWall, cost, time, dp), cost[i] + solve(i + 1, nWall - 1 - time[i], cost, time, dp));
    }

    int paintWalls(vector<int> &cost, vector<int> &time) {
        vector<vector<int>> dp(cost.size(), vector<int>(cost.size() + 1, -1));
        return solve(0, cost.size(), cost, time, dp);
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}