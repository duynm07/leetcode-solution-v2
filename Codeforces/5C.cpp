#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    vector<int> dp(s.length(), 0);

    int ans = 0;
    int cnt = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty())
                continue;
            int length = i - st.top() + 1;
            dp[i] = st.top() == 0 ? length : dp[st.top() - 1] + length;
            st.pop();
            if (dp[i] > ans) {
                ans = dp[i];
                cnt = 1;
            } else if (dp[i] == ans) {
                cnt++;
            }
        }
    }

    cout << ans << " " << cnt;
}