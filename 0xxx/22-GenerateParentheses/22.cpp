#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void build(int i, int n, int &counter, string &s, vector<string> &ans) {
        if (i > n) {
            if (counter == 0)
                ans.push_back(s);
            return;
        }
        for (char c : {'(', ')'}) {
            if (counter == 0 && c == ')')
                continue;

            s = s + c;
            if (c == '(')
                counter++;
            else
                counter--;

            if (counter <= n - i)
                build(i + 1, n, counter, s, ans);

            if (c == '(')
                counter--;
            else
                counter++;

            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int counter = 0;
        vector<string> ans;
        build(1, 2 * n, counter, s, ans);
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> ans = sol.generateParenthesis(8);
    cout << ans.size() << endl;
}