#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            if (count.count(c) == 0)
                count[c] = 0;
            count[c]++;
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            int m = 0;
            char cm;
            for (char c : s) {
                if ((i == 0 || ans[i - 1] != c) && count[c] > m) {
                    cm = c;
                    m = count[c];
                }
            }
            if (m == 0)
                return "";
            count[cm]--;
            ans += cm;
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.reorganizeString("baaba");
}