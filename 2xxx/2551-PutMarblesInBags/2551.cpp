#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int> &weights, int k) {
        int n = weights.size();
        if (k == n)
            return 0;

        vector<int> pairWeights;
        for (int i = 0; i < n - 1; i++)
            pairWeights.push_back(weights[i] + weights[i + 1]);
        sort(pairWeights.begin(), pairWeights.end());

        for (int i = 0; i < pairWeights.size(); i++) {
            cout << pairWeights[i] << " ";
        }

        int ans = 0;
        for (int i = 0; i < k - 1 ; i++)
            ans += pairWeights[n - i - 2] - pairWeights[i];

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> weights = {1, 4, 2, 5, 2};
    cout << sol.putMarbles(weights, 3);
}