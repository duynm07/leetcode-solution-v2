#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        return z * 2 + 4 * min(x, y) + 2 * (x != y);
    }

    vector<string> ans;

    void attemp(string s, int x, int y, int z, int n) {
        if (s.length() == 2 * n) {
            // cout << s << endl;
            ans.push_back(s);
            return;
        }
        int l = s.length();
        if (x > 0 && (l == 0 || s[l - 1] != 'A')) {
            attemp(s + "AA", x - 1, y, z, n);
        }
        if (z > 0 && (l == 0 || s[l - 1] != 'A' || s[l - 2] != 'A')) {
            attemp(s + "AB", x, y, z - 1, n);
        }
        if (y > 0 && (l == 0 || s[l - 1] != 'B')) {
            attemp(s + "BB", x, y - 1, z, n);
        }
    }
};

int main() {
    Solution sol = Solution();
    // int ans = sol.longestString(50, 50, 50);
    // cout << ans;
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    sol.attemp("", x, y, z, n);

    // freopen("out.txt", "w", stdout);

    cout << sol.ans.size() << endl;
    for (int i = 0; i < sol.ans.size(); i++) {
        cout << sol.ans[i] << endl;
    }
}