#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= 3; i++) {
            dp[i] = i;
        }

        for (int num = 4; num <= n; num++) {
            for (int i = 1; i < num; i++) {
                dp[num] = max(dp[num], i * dp[num - i]);
            }
        }

        for (int i = 2; i <= n; i++) {
            cout << "else if (n == " << i << ") return " << dp[i] << ";" << endl;
        }

        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.integerBreak(58);

    return 0;
}