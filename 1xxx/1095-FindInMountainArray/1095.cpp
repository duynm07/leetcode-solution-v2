#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class MountainArray {
public:
    vector<int> arr;
    MountainArray(vector<int> arr) {
        this->arr = arr;
    }
    int get(int index) {
        return arr[index];
    };
    int length() {
        return arr.size();
    };
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // Find peek
        int peekIndex = -1;
        int first = 0;
        int last = n - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            int curr = mountainArr.get(mid);
            if (mid == 0 || mid == n - 1) {
                peekIndex = mid;
                break;
            }
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);
            if (prev < curr && curr > next) {
                peekIndex = mid;
                break;
            }
            if (prev < curr && curr < next) {
                if (curr == target)
                    return mid;
                first = mid + 1;
            } else
                last = mid - 1;
        }

        // Search on left half
        first = 0;
        last = peekIndex;
        while (first <= last) {
            int mid = (first + last) / 2;
            int curr = mountainArr.get(mid);
            if (curr == target)
                return mid;
            else if (curr < target)
                first = mid + 1;
            else
                last = mid - 1;
        }

        // Search on right half
        first = peekIndex + 1;
        last = n - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            int curr = mountainArr.get(mid);
            if (curr == target)
                return mid;
            else if (curr < target)
                last = mid - 1;
            else
                first = mid + 1;
        }

        return -1;
    }
};

int main() {
    Solution sol = Solution();

    // vector<int> arr = {1, 2, 3, 4, 5, 3, 1};
    vector<int> arr = {1, 2, 3, 4, 5};
    MountainArray mntArr(arr);
    cout << sol.findInMountainArray(6, mntArr);

    return 0;
}