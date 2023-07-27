#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        vector<int> ps;
        unordered_map<int, int> f;
        f[0] = 0;
        int n = nums.size();

        ps.push_back(0);
        for (int i = 0; i < n; i++) {
            int val = (ps[i] + nums[i] % k) % k;
            ps.push_back(val);
            if (f.count(val) > 0 && i + 1 - f[val] > 1) {
                cout << i << endl;
                return true;
            }
            if (f.count(val) == 0)
                f[val] = i + 1;
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 0, 1, 0, 1};
    bool ans = sol.checkSubarraySum(nums, 4);
    cout << ans;
}