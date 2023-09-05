#include <cctype>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void build(string &s, int i, vector<string> &ans) {
        int n = s.length();
        if (i == n) {
            ans.push_back(s);
            return;
        }
        if (s[i] >= '0' && s[i] <= '9')
            build(s, i + 1, ans);
        else
            for (int j = 0; j < 2; j++) {
                s[i] = j ? toupper(s[i]) : tolower(s[i]);
                build(s, i + 1, ans);
            }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        build(s, 0, ans);
        return ans;
    }
};