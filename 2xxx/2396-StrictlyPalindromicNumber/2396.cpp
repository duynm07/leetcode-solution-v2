#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base < n - 1; base++) {
            vector<int> bits;
            int num = n;
            while (num > 0) {
                bits.push_back(num % base);
                num /= base;
            }

            int l = bits.size();
            for (int i = 0; i < l / 2; i++)
                if (bits[i] != bits[l - i - 1])
                    return false;
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    for (int i = 4; i < 100000; i++) {
        bool ans = solution.isStrictlyPalindromic(i);
        if (ans)
            cout << i << " ";
            break;
    }

    return 0;
}