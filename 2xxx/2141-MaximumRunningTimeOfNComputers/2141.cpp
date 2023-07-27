#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(long long time, int n, vector<int> &batteries) {
        long long sum = 0;
        for (int battery : batteries) {
            sum += min((long long)battery, time);
        }
        return sum >= time * n;
    }

    long long maxRunTime(int n, vector<int> &batteries) {
        long long first = 1;
        long long last = 0;
        for (int battery : batteries)
            last += battery;
        last = last / n;

        long long ans = 0;

        while (first <= last) {
            long long mid = (first + last) / 2;
            if (check(mid, n, batteries)) {
                ans = mid;
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
}