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
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    if (st.empty())
        cout << "Yes";
    else
        cout << "No";
}