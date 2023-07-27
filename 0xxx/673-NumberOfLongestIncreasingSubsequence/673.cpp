#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        nums.push_back(1e9);
        vector<int> f(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) {
                    if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        count[i] = 0;
                    }
                    if (f[j] + 1 == f[i]) {
                        count[i] += count[j];
                    }
                }

        for (int i = 0; i < nums.size(); i++) {
            cout << count[i] << " ";
        }
        cout << endl;

        return count[nums.size() - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {2, 2, 2, 2, 2};
    cout << sol.findNumberOfLIS(nums) << endl;
}