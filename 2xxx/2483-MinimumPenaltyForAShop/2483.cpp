#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int total = 0;

        for (int i = 0; i < n; i++)
            total += customers[i] == 'Y';

        int minPen = customers.length() + 10;
        int ans = 0;
        int currentTotal = 0;
        for (int i = 0; i <= n; i++) {
            int pen = i + total - 2 * currentTotal;
            if (pen < minPen) {
                minPen = pen;
                ans = i;
            }
            if (i < n)
                currentTotal += customers[i] == 'Y';
        }

        return ans;
    }
};

int main()
{
    Solution sol = Solution();
    cout << sol.bestClosingTime("YNNYNYNYNYYNNNYYYNYNYNYNNNYNYNYNYNNYNYNYNYYYNYNYNNNYNYNY");
}