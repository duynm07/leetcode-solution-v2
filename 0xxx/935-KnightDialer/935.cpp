#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const unordered_map<int, vector<int>> STEP{
        {0, {4, 6}},
        {1, {6, 8}},
        {2, {7, 9}},
        {3, {4, 8}},
        {4, {0, 3, 9}},
        {5, {}},
        {6, {0, 1, 7}},
        {7, {2, 6}},
        {8, {1, 3}},
        {9, {2, 4}},
    };
    const static int MOD = 1e9 + 7;

    int calculate(vector<vector<int>> &memo, int k, int n) {
        if (n == 1)
            return 10;
        if (memo[k][n] >= 0)
            return memo[k][n];

        int ans = 0;
        vector<int> steps = STEP.at(k);
        for (int u : steps) {
            ans = (ans + calculate(memo, u, n - 1)) % MOD;
        }

        return ans;
    }

    int knightDialer(int n) {
        vector<vector<int>> memo(10, vector<int>(n + 1, -1));
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + calculate(memo, i, n)) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}