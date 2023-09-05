#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        int current = 0;
        vector<bool> flag(n * k + 1, false);
        while (n > 0) {
            current++;
            if (current > k || !flag[k - current]) {
                cout << current << " ";
                ans += current;
                flag[current] = true;
                n--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol = Solution();
    cout << sol.minimumSum(2, 6);
}