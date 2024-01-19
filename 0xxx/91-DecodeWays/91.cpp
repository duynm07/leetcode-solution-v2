#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 1; i < s.length(); i++) {
            bool c1 = s[i] != '0';
            bool c2 = s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6');
            int temp = prev1;
            prev1 = prev1 * c1 + prev2 * c2;
            prev2 = temp;
        }
        
        return prev1;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.numDecodings("12");

    return 0;
}