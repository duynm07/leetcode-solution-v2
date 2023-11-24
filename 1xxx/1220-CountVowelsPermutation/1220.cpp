#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int idx = 1; idx < n; idx++) {
            long long aNext = (e + i + u) % MOD;
            long long eNext = (a + i) % MOD;
            long long iNext = (e + o) % MOD;
            long long oNext = i % MOD;
            long long uNext = (i + o) % MOD;

            a = aNext;
            e = eNext;
            i = iNext;
            o = oNext;
            u = uNext;
        }

        return (a + e + i + o + u) % MOD;
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.countVowelPermutation(5);

    return 0;
}