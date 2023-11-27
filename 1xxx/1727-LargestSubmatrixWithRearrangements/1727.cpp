#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int calc(vector<int> &nums) {
        sort(nums.begin(), nums.end(), greater());

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i] * (i + 1));
        }

        return ans;
    }

    int largestSubmatrix(vector<vector<int>> &matrix) {
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] = matrix[i - 1][j] + 1;

        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
            ans = max(ans, calc(matrix[i]));

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}