#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int num = 1;
        long long ans = 0;
        vector<bool> f(target + n, true);
        for (int i = 0; i < n; i++) {
            while (!f[num])
                num++;
            f[num] = false;
            if (target >= num)
                f[target - num] = false;
            ans += (long long)num;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    // cout << sol.minimumPossibleSum(2, 3);
    // cout << sol.minimumPossibleSum(3, 3);
    cout << sol.minimumPossibleSum(1, 1);
}