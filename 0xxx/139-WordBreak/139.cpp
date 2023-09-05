#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.length();
        vector<bool> f(n);
        f[0] = find(wordDict.begin(), wordDict.end(), s.substr(0, 1)) != wordDict.end();
        for (int i = 1; i < n; i++) {
            f[i] = find(wordDict.begin(), wordDict.end(), s.substr(0, i + 1)) != wordDict.end();
            for (int j = 0; j < i && !f[i]; j++)
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j + 1, i - j)) != wordDict.end())
                    f[i] = true;
        }
        return f[n - 1];
    }
};

int main() {
    Solution sol = Solution();
    vector<string> wordDict = {"leet", "code"};
    cout << sol.wordBreak("leetcode", wordDict);
}