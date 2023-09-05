#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int count_ = 0;
        for (char c : moves) {
            if (c == 'L')
                ans++;
            else if (c == 'R')
                ans--;
            else
                count_++;
        }
        return abs(ans) + count_;
    }
};