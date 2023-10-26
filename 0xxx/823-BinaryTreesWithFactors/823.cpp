#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] > 0)
                    continue;
                dp[arr[i]] = ((long long)dp[arr[i]] + ((long long)dp[arr[j]] * (long long)dp[arr[i] / arr[j]]) % MOD) % MOD;
            }
            ans = ((long long)ans + (long long)dp[arr[i]]) % MOD;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    // vector<int> nums = {2, 4, 5, 10};
    vector<int> nums = {2, 4};
    cout << sol.numFactoredBinaryTrees(nums);

    return 0;
}