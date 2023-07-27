#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        if (n >= 333)
            return false;
        int checkNumber = ((n * 1000) + 2 * n) * 1000 + 3 * n;
        vector<bool> f(10, false);
        while (checkNumber > 0) {
            f[checkNumber % 10] = true;
            checkNumber /= 10;
        }
        if (f[0])
            return false;
        for (int i = 1; i < 10; i++) {
            if (!f[i])
                return false;
        }
        return true;
    }
};