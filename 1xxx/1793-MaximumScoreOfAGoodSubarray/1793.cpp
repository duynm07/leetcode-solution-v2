#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        vector<int> minArr(nums.size(), INT_MAX);
        minArr[k] = nums[k];

        for (int i = k - 1; i >= 0; i--)
            minArr[i] = min(nums[i], minArr[i + 1]);

        for (int i = k + 1; i < nums.size(); i++) {
            minArr[i] = min(nums[i], minArr[i - 1]);
        }

        int ans = nums[k];

        for (int i = 0; i <= k; i++) {
            int first = k;
            int last = nums.size() - 1;
            while (first <= last) {
                int mid = (first + last) / 2;
                if (minArr[mid] >= minArr[i]) {
                    ans = max(ans, minArr[i] * (mid - i + 1));
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
        }

        for (int i = k; i < nums.size(); i++) {
            int first = 0;
            int last = k;
            while (first <= last) {
                int mid = (first + last) / 2;
                if (minArr[mid] >= minArr[i]) {
                    ans = max(ans, minArr[i] * (i - mid + 1));
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    // vector<int> nums = {5, 5, 4, 5, 4, 1, 1, 1};

    cout << sol.maximumScore(nums, 3);

    return 0;
}