#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int checkTimes(int nBuckets, int nPigs, vector<vector<int>> &memo) {
        if (nPigs == 0)
            return 1e6; // Just some big number

        if ((nBuckets - 1) / nPigs <= 1)
            return 1;

        if (memo[nBuckets][nPigs] >= 0)
            return memo[nBuckets][nPigs];

        if ((nBuckets - 1) % nPigs)
            return memo[nBuckets][nPigs] = checkTimes((nBuckets - 1) / nPigs + 1, nPigs - 1, memo) + 1;
        else
            return memo[nBuckets][nPigs] = checkTimes((nBuckets - 1) / nPigs, nPigs - 1, memo) + 1;
    }

    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        vector<vector<int>> memo(buckets + 1, vector<int>(buckets + 1, -1));
        int first = 1;
        int last = buckets;
        int ans = buckets;
        while (first <= last) {
            int mid = (first + last) / 2;
            int times = checkTimes(buckets, mid, memo);
            if (minutesToDie * times <= minutesToTest) {
                last = mid - 1;
                ans = mid;
            } else
                first = mid + 1;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.poorPigs(4, 15, 30);

    return 0;
}