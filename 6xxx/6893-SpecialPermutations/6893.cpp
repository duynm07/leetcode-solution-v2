#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find all possible paths
    int findAllPaths(int N, vector<vector<int>> &graph, int mod) {
        // Initialize a dp array
        long long dp[N][(1 << N)];
        // Initialize it with 0
        memset(dp, 0, sizeof dp);
        // Initialize for the first vertex
        dp[0][1] = 1;
        // Iterate over all the masks
        for (int i = 2; i < (1 << N); i++) {
            // If the first vertex is absent
            if ((i & (1 << 0)) == 0)
                continue;
            // Only consider the full subsets
            if ((i & (1 << (N - 1))) && i != ((1 << N) - 1))
                continue;
            // Choose the end city
            for (int end = 0; end < N; end++) {
                // If this city is not in the subset
                if (i & (1 << end) == 0)
                    continue;
                // Set without the end city
                int prev = i - (1 << end);
                // Check for the adjacent cities
                for (int it : graph[end]) {
                    if ((i & (1 << it))) {
                        dp[end][i] = ((dp[end][i] % mod) + (dp[it][prev] % mod)) % mod;
                    }
                }
            }
        }

        // Print the answer
        return (int) dp[N - 1][(1 << N) - 1];
    }

    int specialPerm(vector<int> &nums) {
        vector<vector<int>> graph;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> adj;
            for (int j = 0; j < n; j++) {
                if (i != j && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0))
                    adj.push_back(j);
            }
            graph.push_back(adj);
        }
        int mod = 1000000007;
        return findAllPaths(n, graph, mod);
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> inp = {2, 3, 6};
    // vector<int> inp = {1, 4, 3};
    vector<int> inp = {1, 4, 32, 15, 3, 2, 21, 5};
    int ans = sol.specialPerm(inp);
    cout << ans;
}