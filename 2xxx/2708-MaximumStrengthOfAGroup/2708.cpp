#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int> &nums) {
        int n = nums.size();
        int count = 1 << n;
        long long ans = nums[0];

        for (int i = 1; i < count; i++) {
            long long strength = 1;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0)
                    strength *= nums[j];
            }
            ans = max(strength, ans);
        }

        return ans;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> a = {1, 2, 3};
    long long ans = solution.maxStrength(a);
    cout << ans;
}