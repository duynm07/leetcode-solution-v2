#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> primes;
    int shorten(int n) {
        int ans = 1;
        for (int prime : primes) {
            int k = 0;
            while (n % prime == 0) {
                n /= prime;
                k++;
            }
            if (k % 2 == 1)
                ans *= prime;
            if (n == 1)
                break;
        }
        return ans;
    }
    unordered_map<int, vector<int>> createSubsets(int n) {
        unordered_map<int, vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            int si = shorten(i);
            if (ans.count(si) == 0)
                ans[si] = {i};
            else
                ans[si].push_back(i);
        }
        return ans;
    }
    long long maximumSum(vector<int> &nums) {
        int n = nums.size();
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i; i * j <= n; j++) {
                    isPrime[i * j] = false;
                }
            }
        }

        for (int i = 1; i <= n; i++)
            if (isPrime[i])
                primes.push_back(i);

        long long ans = 0;

        unordered_map<int, vector<int>> subsets = createSubsets(n);
        for (auto subset : subsets) {
            long long currSum = 0;
            vector<int> elements = subset.second;
            for (int i : elements)
                currSum += nums[i - 1];
            ans = max(ans, currSum);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {5, 10, 3, 10, 1, 13, 7, 9, 4};
    vector<int> nums = {8, 7, 3, 5, 7, 2, 4, 9};
    cout << sol.maximumSum(nums);

    return 0;
}