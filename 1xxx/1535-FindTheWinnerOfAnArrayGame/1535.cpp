#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int maxElement = 0;
        for (int i = 0; i < arr.size(); i++)
            maxElement = max(maxElement, arr[i]);

        int streak = 1;
        int prevWinner = max(arr[0], arr[1]);

        for (int i = 2; i < arr.size() && streak < k && prevWinner != maxElement; i++) {
            streak = prevWinner > arr[i] ? streak + 1 : 1;
            prevWinner = max(prevWinner, arr[i]);
        }

        return prevWinner;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {2, 1, 3, 5, 4, 6, 7};
    cout << sol.getWinner(nums, 2);

    return 0;
}