#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0);
        for (char ch : s)
            f[ch - 'a']++;

        vector<bool> used(s.length() + 1, false);
        int ans = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (f[ch - 'a'] == 0)
                continue;
            while (used[f[ch - 'a']] && f[ch - 'a'] > 0) {
                ans++;
                f[ch - 'a']--;
            }
            if (f[ch - 'a'] > 0)
                used[f[ch - 'a']] = true;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.minDeletions("aab");
}