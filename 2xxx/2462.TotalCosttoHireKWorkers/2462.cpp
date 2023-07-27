#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        int n = costs.size();

        if (n <= 2 * candidates) {
            long long ans = 0;
            sort(costs.begin(), costs.end());
            for (int i = 0; i < k; i++)
                ans += (long long)costs[i];
            return ans;
        }

        priority_queue<int, vector<int>, greater<int>> headQueue, tailQueue;
        int headIdx, tailIdx;

        for (int i = 0; i < candidates; i++) {
            headQueue.push(costs[i]);
            tailQueue.push(costs[n - i - 1]);
        }

        headIdx = candidates - 1;
        tailIdx = n - candidates;
        long long ans = 0;

        for (int i = 0; i < k; i++) {
            if (tailQueue.size() > 0 && (headQueue.size() == 0 || headQueue.top() > tailQueue.top())) {
                ans += (long long)tailQueue.top();
                tailQueue.pop();
                if (tailIdx - 1 > headIdx)
                    tailQueue.push(costs[--tailIdx]);
            } else {
                ans += (long long)headQueue.top();
                headQueue.pop();
                if (headIdx + 1 < tailIdx)
                    headQueue.push(costs[++headIdx]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> costs = {2, 1, 1};
    long long ans = sol.totalCost(costs, 3, 1);
    cout << ans;
}