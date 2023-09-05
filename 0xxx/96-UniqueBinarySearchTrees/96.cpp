#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int end, int start = 1) {
        if (start >= end)
            return 1;
        int ans = 0;
        for (int i = start; i <= end; i++) {
            ans += numTrees(i - 1, start) * numTrees(end, i + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    for (int i = 1; i < 20; i++) {
        cout << "if (n == " << i << ") return " << sol.numTrees(i) << ";" << endl;
    }
}