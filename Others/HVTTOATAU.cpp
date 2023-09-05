#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<int> A, B;
        for (int i = n; i > 0; i--) {
            A.push(i);
        }

        bool check = true;

        for (int i = 0; i < n; i++) {
            int ci;
            cin >> ci;
            if (!B.empty() && B.top() == ci) {
                B.pop();
            } else {
                while (!A.empty() && A.top() != ci) {
                    B.push(A.top());
                    A.pop();
                }
                if (A.empty()) {
                    check = false;
                } else {
                    A.pop();
                }
            }
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}