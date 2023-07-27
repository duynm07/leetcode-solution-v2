#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(vector<int> &locations, int current, int finish, int remainFuel, vector<vector<int>> &memo) {
        if (memo[current][remainFuel] >= 0)
            return memo[current][remainFuel];

        int ans = current == finish ? 1 : 0;
        for (int j = 0; j < locations.size(); j++) {
            if (j != current && abs(locations[j] - locations[current]) <= remainFuel) {
                ans = (ans + solve(locations, j, finish, remainFuel - abs(locations[j] - locations[current]), memo)) % MOD;
            }
        }

        return memo[current][remainFuel] = ans;
    }

    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        vector<vector<int>> memo(locations.size(), vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, memo);
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> locations = {2, 3, 6, 8, 4};
    vector<int> locations = {1, 2, 3};
    // vector<int> locations = {4, 3, 1};
    // vector<int> locations = {5, 2, 1};
    int ans = sol.countRoutes(locations, 0, 2, 40);
    cout << ans;
}