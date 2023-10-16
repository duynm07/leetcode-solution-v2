#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<int, int>> primeFactors(long long n) {
    vector<pair<int, int>> factors;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            int e = 0;
            while (n % i == 0) {
                e++;
                n /= i;
            }
            factors.push_back({i, e});
        }

    if (n > 1)
        factors.push_back({n, 1});

    return factors;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> ps = primeFactors(m);

    long long k = -1;

    for (int i = 0; i < ps.size(); i++) {
        int p = ps[i].first;
        int q = ps[i].second;
        long long e = 0;
        long long curr = p;
        while (n >= curr) {
            e += n / curr;
            curr *= p;
        }
        if (k < 0 || e / q < k)
            k = e / q;
    }

    cout << k;

    return 0;
}