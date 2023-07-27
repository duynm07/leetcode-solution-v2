#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (long long i = 2; i < n; i++) {
            if (isPrime[i]) {
                for (long long j = i; i * j < n; j++) {
                    isPrime[i * j] = false;
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 2; i <= n / 2; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                // vector<int> temp = {i, n - i};
                ans.push_back({i, n - i});
            }
        }

        return ans;
    }
};