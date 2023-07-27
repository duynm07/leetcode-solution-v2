#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> f;

    bool check(string s, string p, int i, int j) {
        if (f[i][j] >= 0)
            return f[i][j];
        if (j >= p.length()) {
            f[i][j] = i >= s.length();
            return i >= s.length();
        }

        bool firstMatch = i < s.length() && (s[i] == p[j] || p[j] == '.');

        if (p.length() - j == 1) {
            f[i][j] = s.length() - i == 1 && firstMatch;
            return s.length() - i == 1 && firstMatch;
        }

        if (p.length() - j >= 2 && p[j + 1] == '*') {
            f[i][j] = check(s, p, i, j + 2) || (firstMatch && check(s, p, i + 1, j));
            return check(s, p, i, j + 2) || (firstMatch && check(s, p, i + 1, j));
        } else {
            f[i][j] = firstMatch && check(s, p, i + 1, j + 1);
            return firstMatch && check(s, p, i + 1, j + 1);
        }
    }

    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        f = vector<vector<int>>(ls + 1, vector<int>(lp + 1, -1));
        return check(s, p, 0, 0);
    }
};

int main() {
    Solution solution = Solution();
    bool ans = solution.isMatch("aab", "c*a*b");
    // bool ans = solution.isMatch("mississippi", "mis*is*p*.");
    // bool ans = solution.isMatch("ab", ".*c");
    cout << ans;
}