#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();

        vector<int> diffIndexex;
        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i])
                diffIndexex.push_back(i);

        if (diffIndexex.size() % 2)
            return -1;

        vector<pair<pair<int, int>, int>> d;
        for (int i = 0; i < diffIndexex.size() - 1; i++)
            for (int j = i + 1; j < diffIndexex.size(); j++)
                d.push_back({{diffIndexex[i], diffIndexex[j]}, min(diffIndexex[j] - diffIndexex[i], x)});

        sort(d.begin(), d.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) { return a.second < b.second; });
        vector<bool> f(n, true);
        int ans = 0;

        for (int i = 0; i < d.size(); i++) {
            cout << d[i].first.first << " " << d[i].first.second << " " << d[i].second << endl;
            if (f[d[i].first.first] && f[d[i].first.second]) {
                ans += d[i].second;
                f[d[i].first.first] = false;
                f[d[i].first.second] = false;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    // cout << sol.minOperations("1100011000", "0101001010", 2);
    // cout << sol.minOperations("10110", "00011", 4);
    cout << sol.minOperations("101101", "000000", 6);

    return 0;
}