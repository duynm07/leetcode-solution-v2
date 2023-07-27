#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            vector<bool> isExists(n + 1, false);
            f[i][i] = 0;
            isExists[nums[i]] = true;
            for (int j = i + 1; j < n; j++) {
                int num = nums[j];
                if (isExists[num]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    if (isExists[num - 1] && isExists[num + 1])
                        f[i][j] = f[i][j - 1] - 1;
                    else if (!isExists[num - 1] && !isExists[num + 1])
                        f[i][j] = f[i][j - 1] + 1;
                    else
                        f[i][j] = f[i][j - 1];
                }
                isExists[num] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                ans += f[i][j];

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {2, 3, 1, 4};
    vector<int> nums = {1, 3, 3, 3, 5};
    cout << sol.sumImbalanceNumbers(nums);
}