#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        vector<vector<int>> p(26, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 26; j++)
                p[j][i] = s[i - 1] - 'a' == j ? p[j][i - 1] + 1 : p[j][i - 1];

        // for (int pi : p[0]) {
        //     cout << pi << " ";
        // }
        // cout << endl;
        // for (int pi : p[1]) {
        //     cout << pi << " ";
        // }
        // cout << endl;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int maxOcc = 0;
                int minOcc = n;
                for (int c = 0; c < 26; c++) {
                    int occurrences = p[c][j] - p[c][i - 1];
                    if (occurrences > 0) {
                        maxOcc = max(occurrences, maxOcc);
                        minOcc = min(occurrences, minOcc);
                        // cout << i << " " << j << " " << (char)(c + 'a') << " - " << occurrences << endl;
                    }
                }
                ans = max(ans, maxOcc - minOcc);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.largestVariance("aababbb");
}