#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    const vector<int> f = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647};

    int findMostSignificantBit(int n) {
        int k = 0;
        while (n != 1) {
            k++;
            n /= 2;
        }
        return k;
    }

    int minimumOneBitOperations(int n) {
        if (n <= 1)
            return n;

        int k = findMostSignificantBit(n);
        int m = n ^ (1 << k);
        return f[k] - minimumOneBitOperations(m);
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.minimumOneBitOperations(3);

    return 0;
}