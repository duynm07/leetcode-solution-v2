#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long totalCost(int nAlloys, vector<int> &comp, vector<int> &stock, vector<int> &cost) {
        long long total = 0;
        for (int i = 0; i < comp.size(); i++)
            if ((long long)nAlloys * (long long)comp[i] > (long long)stock[i])
                total += ((long long)nAlloys * (long long)comp[i] - (long long)stock[i]) * (long long)cost[i];
        return total;
    };

    int maxAlloys(int budget, vector<int> &comp, vector<int> &stock, vector<int> &cost) {
        int first = 0;
        int last = 1e9;
        int ans = 0;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (totalCost(mid, comp, stock, cost) <= (long long)budget) {
                ans = mid;
                first = mid + 1;
            } else
                last = mid - 1;
        }
        return ans;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        int ans = 0;
        for (int i = 0; i < k; i++)
            ans = max(ans, maxAlloys(budget, composition[i], stock, cost));
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> composition = {{1, 1, 1}, {1, 1, 10}};
    vector<int> stock = {0, 0, 0};
    vector<int> cost = {1, 2, 3};

    cout << sol.maxNumberOfAlloys(3, 2, 15, composition, stock, cost);

    return 0;
}