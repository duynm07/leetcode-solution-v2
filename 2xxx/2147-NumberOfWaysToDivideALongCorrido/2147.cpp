#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const static int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int countP = 0;
        int countS = 0;
        long long ans = 1;

        for (char c : corridor) {
            if (c == 'S') {
                countS++;
                if (countS % 2 == 1 && countS > 1) {
                    ans = (ans * (countP + 1)) % MOD;
                }
                countP = 0;
            } else {
                if (countS > 0 && countS % 2 == 0) {
                    countP++;
                }
            }
        }

        return countS == 0 || countS % 2 ? 0 : ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.numberOfWays("SSPPSPSPPSSPPPPPPSSSS") << endl;
    cout << sol.numberOfWays("PPPPSSPPSPSPPSSPPPPPPSSSS") << endl;
    cout << sol.numberOfWays("PPSPSP") << endl;
    cout << sol.numberOfWays("S") << endl;

    return 0;
}