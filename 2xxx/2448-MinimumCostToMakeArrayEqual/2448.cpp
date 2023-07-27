#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool comparePairs(pair<long long, long long> p1, pair<long long, long long> p2) {
        // Compare based on the first element of the pair
        return p1.first < p2.first;
    }

    long long minCost(vector<int> &nums, vector<int> &cost) {
        int n = nums.size();
        vector<pair<long long, long long>> a(n + 1, {0, 0});
        for (int i = 0; i < n; i++) {
            a[i + 1].first = nums[i];
            a[i + 1].second = cost[i];
        }
        sort(a.begin(), a.end(), comparePairs);

        vector<long long> pCost(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pCost[i] = pCost[i - 1] + a[i].second;
        }

        long long minCost = 0;
        for (int i = 1; i <= n; i++) {
            minCost += a[i].second * (a[i].first - a[1].first);
        }

        long long currentCost = minCost;
        for (int i = 2; i <= n; i++) {
            long long delta = a[i].first - a[i - 1].first;
            currentCost = currentCost + delta * pCost[i - 1] - delta * (pCost[n] - pCost[i - 1]);
            minCost = min(minCost, currentCost);
        }

        return minCost;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 3, 5, 2};
    vector<int> costs = {2, 3, 1, 14};
    long long ans = sol.minCost(nums, costs);
    cout << ans;
}