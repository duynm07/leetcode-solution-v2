#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:

    int maximizeTheProfit(int n, vector<vector<int>> &offers) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        unordered_map<int, vector<pair<int, int>>> endOffers;

        for (vector<int> offer : offers) {
            if (endOffers.count(offer[1]) == 0) {
                endOffers[offer[1]] = {{offer[0], offer[2]}};
            } else {
                endOffers[offer[1]].push_back({offer[0], offer[2]});
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (endOffers.count(i - 1) > 0) {
                vector<pair<int, int>> okOffers = endOffers[i - 1];
                for (pair<int, int> offer : okOffers) {
                    dp[i] = max(dp[i], dp[offer.first] + offer.second);
                }
            }
            // cout << i << " " << dp[i] << endl;
        }

        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
    // vector<vector<int>> offers = {{0, 0, 1}, {0, 2, 2}, {1, 3, 2}};
    vector<vector<int>> offers = {{0, 0, 1}, {0, 2, 10}, {1, 3, 2}};
    cout << sol.maximizeTheProfit(5, offers);
}