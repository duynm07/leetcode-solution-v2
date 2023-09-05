#include <cctype>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void build(int n, int k, int &count, string &s, int i, string &ans) {
        if (count >= k)
            return;
        if (i == n) {
            if (++count == k)
                ans = s;
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (i == 0 || ch != s[i - 1]) {
                s += ch;
                build(n, k, count, s, i + 1, ans);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        string ans = "";
        int count = 0;
        build(n, k, count, s, 0, ans);
        return to_string(count);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.getHappyString(20, 1000000000);
}