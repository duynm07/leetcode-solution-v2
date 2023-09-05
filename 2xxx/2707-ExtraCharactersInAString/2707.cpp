#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAppear(string s, vector<string> &dictionary) {
        for (string word : dictionary)
            if (s == word)
                return true;
        return false;
    }
    int minExtraChar(string s, vector<string> &dictionary) {
        vector<int> dp(s.length(), s.length());
        dp[0] = isAppear(s.substr(0, 1), dictionary) ? 0 : 1;
        for (int i = 1; i < s.length(); i++) {
            if (isAppear(s.substr(0, i + 1), dictionary)) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                string subStr = s.substr(j + 1, i - j);
                int extraChar = isAppear(subStr, dictionary) ? 0 : i - j;
                dp[i] = min(dp[i], dp[j] + extraChar);
            }
        }

        return dp[s.length() - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<string> dictionary = {"leet", "code", "leetcode"};
    cout << sol.minExtraChar("leetscode", dictionary);
}