#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    //     if (k == 1)
    //         return nums;

    //     vector<int> ans;
    //     priority_queue<pair<int, int>> pq;
    //     for (int i = 0; i < nums.size(); i++) {
    //         pq.push({nums[i], i});
    //         if (i >= k - 1) {
    //             while (pq.top().second <= i - k)
    //                 pq.pop();
    //             ans.push_back(pq.top().first);
    //         }
    //     }
    //     return ans;
    // }

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (k == 1)
            return nums;

        vector<int> ans;

        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && i - dq.back() >= k)
                dq.pop_back();
            while (!dq.empty() && nums[dq.front()] <= nums[i])
                dq.pop_front();
            dq.push_front(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.back()]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for (int a : ans)
        cout << a << " ";
}