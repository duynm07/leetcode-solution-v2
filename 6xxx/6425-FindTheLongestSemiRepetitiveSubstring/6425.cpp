#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 0;
        int j = 0;
        int p = -1;
        int ans = 0;
        while (true) {
            j++;
            if (j >= s.length()) {
                ans = max(ans, j - i);
                break;
            }
            if (s[j] == s[j - 1]) {
                if (p >= 0) {
                    ans = max(ans, j - i);
                    i = p;
                }
                p = j;
            }
        }
        return ans;
    }
};