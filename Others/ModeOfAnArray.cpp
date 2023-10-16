#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int solve(vector<int> a, int k) {
    unordered_map<int, int> f;
    int fk = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == k) {
            fk++;
            continue;
        }
        if (f.count(a[i]) == 0)
            f[a[i]] = 0;
        f[a[i]]++;
    }

    if (fk > a.size() / 2)
        return 0;

    priority_queue<int> q;
    for (const auto &pair : f) {
        q.push(pair.second);
    }

    int ans = 0;
    while (fk <= q.top()) {
        ans++;
        fk++;
        q.push(q.top() - 1);
        q.pop();
    }

    return ans;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, k) << endl;
    }
}