#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, int> tallestDiff(vector<int> &rods, int left, int right) {
        vector<pair<int, int>> steels = {{0, 0}};
        for (int i = left; i < right; i++) {
            int rodHeight = rods[i];
            int currentSize = steels.size();
            for (int j = 0; j < currentSize; j++) {
                pair<int, int> steel = steels[j];
                steels.push_back({steel.first + rodHeight, steel.second});
                steels.push_back({steel.first, steel.second + rodHeight});
            }
        }

        unordered_map<int, int> diff = {{0, 0}};
        for (pair<int, int> steel : steels) {
            int left = steel.first;
            int right = steel.second;
            if (diff.count(left - right) > 0) {
                diff[left - right] = max(diff[left - right], left);
            } else {
                diff[left - right] = left;
            }
        }

        return diff;
    }

    int tallestBillboard(vector<int> &rods) {
        int n = rods.size();
        if (n == 1) {
            return 0;
        } else if (n == 2) {
            return rods[0] == rods[1] ? rods[0] : 0;
        }

        int mid = n / 2;

        unordered_map<int, int> leftDiff = tallestDiff(rods, 0, mid);
        unordered_map<int, int> rightDiff = tallestDiff(rods, mid, n);

        int ans = 0;

        for (const auto &pair : leftDiff) {
            int key = pair.first;
            if (rightDiff.count(-key) > 0) {
                ans = max(ans, pair.second + rightDiff[-key]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> rods = {1, 2, 3, 6};
    int ans = sol.tallestBillboard(rods);
    // cout << ans;
}