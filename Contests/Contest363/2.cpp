#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countWays(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] > 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < i + 1 && nums[i + 1] > i + 1)
                ans++;
        }
        ans += nums[n - 1] < n;
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}