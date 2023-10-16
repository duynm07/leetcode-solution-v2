#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int currPos, int remainStep, int arrLen, vector<vector<int>> &memo) {
        int MOD = 1e9 + 7;
        if (remainStep == currPos)
            return 1;
        if (remainStep < currPos)
            return 0;

        if (memo[currPos][remainStep] >= 0)
            return memo[currPos][remainStep];

        int ans = solve(currPos, remainStep - 1, arrLen, memo);

        if (currPos > 0)
            ans = ((long long)ans + solve(currPos - 1, remainStep - 1, arrLen, memo)) % MOD;
        if (currPos < arrLen - 1)
            ans = ((long long)ans + solve(currPos + 1, remainStep - 1, arrLen, memo)) % MOD;

        return memo[currPos][remainStep] = ans;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps / 2 + 1);
        vector<vector<int>> memo(arrLen, vector<int>(steps + 1, -1));
        return solve(0, steps, arrLen, memo);
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.numWays(2, 4);

    return 0;
}