#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        vector<int> ps;

        ps.push_back(0);

        cout << ps[0];
        for (int i = 0; i < nums.size(); i++) {
            ps.push_back(ps[i] + nums[i]);
            cout << " " << ps[i + 1];
        }
        cout << endl;

        unordered_map<int, int> counter;
        int ans = 0;

        for (int i = 0; i < ps.size(); i++) {
            ans += counter[ps[i] - k];
            counter[ps[i]] += 1;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {-1, -1, 1};
    cout << sol.subarraySum(nums, 1);

    return 0;
}