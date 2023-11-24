#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int> &nums, int k) {
        int ans = nums[0];

        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});

        for (int i = 1; i < nums.size(); i++) {
            while (i - maxHeap.top().second > k)
                maxHeap.pop();
            int curr = maxHeap.top().first < 0 ? nums[i] : maxHeap.top().first + nums[i];
            int curr = nums[i] + max(0, maxHeap.top().first);
            maxHeap.push({curr, i});
            ans = max(ans, curr);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {10, 2, -10, 5, 20};
    cout << sol.constrainedSubsetSum(nums, 2);

    return 0;
}