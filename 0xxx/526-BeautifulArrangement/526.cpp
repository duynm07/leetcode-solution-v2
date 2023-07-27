#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans;
    vector<int> x;
    vector<bool> f;
    void build(int i, int n) {
        if (i > n) {
            // for (int j = 0; j < n; j++) {
            //     cout << x[j + 1] << " ";
            // }
            // cout << endl;
            ans++;
            return;
        }
        for (int j = 1; j <= n; j++) {
            if ((i % j == 0 || j % i == 0) && f[j]) {
                x[i] = j;
                f[j] = false;
                build(i + 1, n);
                f[j] = true;
            }
        }
    }
    int countArrangement(int n) {
        ans = 0;
        x.resize(n + 1);
        f.resize(n + 1, true);
        build(1, n);
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    int n;
    cin >> n;
    int ans = sol.countArrangement(n);
    cout << ans;
} 