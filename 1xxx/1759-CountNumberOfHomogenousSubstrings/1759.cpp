#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int lastCount = 1;
        int ans = 1;
        for (int i = 1; i < s.length(); i++) {
            lastCount = s[i] == s[i - 1] ? (lastCount + 1) % MOD : 1;
            ans = ((long long)ans + lastCount) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}