#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

int solve(vector<int> &a) {
    int n = a.size();
    stack<int> st;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int height = a[i];
        while (!st.empty() && a[st.top() - 1] < a[i]) {
            height = min(height, st.top());
            st.pop();
        }
        st.push(i + 1);
        int size = st.size();
        ans = max(ans, height * size);
        cout << height << "*" << size << "=" << height * size << endl;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << endl;
    }
}