#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;

        string ans = "";
        string current = "";
        for (char c : s) {
            current = current + c;
            if (c == '(') {
                st.push(c);
            } else {
                st.pop();
            }
            if (st.empty()) {
                ans += current.substr(1, current.length() - 2);
                current = "";
            }
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.removeOuterParentheses("(()())(())");
}