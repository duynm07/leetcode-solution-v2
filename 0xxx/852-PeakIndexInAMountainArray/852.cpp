#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int first = 0;
        int last = arr.size() - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (mid == 0) {
                first = mid + 1;
                continue;
            }
            if (mid == arr.size() - 1) {
                last = mid - 1;
                continue;
            }
            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                return mid;
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
                first = mid + 1;
            else
                last = mid - 1;
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {3, 5, 3, 2, 0};
    cout << sol.peakIndexInMountainArray(arr);
}