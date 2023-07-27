#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int number, int k) {
        if (number == k)
            return true;
        if (number < k)
            return false;
        int d = 10;
        while (number > d) {
            int p1 = number / d;
            int p2 = number % d;
            if (p2 < k && check(p1, k - p2))
                return true;
            d *= 10;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i * i, i))
                ans += i * i;
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();
    int c = solution.punishmentNumber(37);
    cout << c << endl;
}