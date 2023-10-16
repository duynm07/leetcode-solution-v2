#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(int n) {
    int ans = 0;
    while (n >= 2) {
        int k = 1;
        while (k * (3 * k + 1) <= 2 * n)
            k++;
        --k;

        ans++;
        n -= (k * (3 * k + 1)) / 2;
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}