#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        if (arr.size() == 1)
            return 1;

        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++)
            arr[i] = min(arr[i], arr[i - 1] + 1);

        return arr[arr.size() - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {4, 67, 5, 2, 46, 7, 4, 2, 4, 6, 7, 4, 2, 2, 2};
    cout << sol.maximumElementAfterDecrementingAndRearranging(arr);

    return 0;
}