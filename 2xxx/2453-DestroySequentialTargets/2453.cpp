#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int destroyTargets(vector<int> &nums, int space) {
        unordered_map<int, int> counts;

        int maxTarget = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (counts.count(nums[i] % space) == 0)
                counts[nums[i] % space] = 0;
            counts[nums[i] % space] += 1;
            maxTarget = max(maxTarget, counts[nums[i] % space]);
        }

        int ans = 1e9;
        for (int i = 0; i < nums.size(); i++)
            if (counts[nums[i] % space] == maxTarget)
                ans = min(ans, nums[i]);
                
        return ans;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums{4, 5, 5, 2, 1};
    int space = 4;

    int ans = solution.destroyTargets(nums, space);

    cout << ans;
}