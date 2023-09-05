#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int first = 0;
        int last = m * n - 1;

        while (first <= last) {
            int mid = (first + last) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target)
                return true;
            if (val > target)
                last = mid - 1;
            else
                first = mid + 1;
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << sol.searchMatrix(matrix, 60);
}