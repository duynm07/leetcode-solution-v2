#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> f(26, false);
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < s.length(); i++)
            lastIndex[s[i] - 'a'] = i;

        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (f[ch - 'a'])
                continue;

            while (!st.empty() && lastIndex[st.top() - 'a'] > i && st.top() > ch) {
                f[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            f[ch - 'a'] = true;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.removeDuplicateLetters("asdfasdf");

    return 0;
}