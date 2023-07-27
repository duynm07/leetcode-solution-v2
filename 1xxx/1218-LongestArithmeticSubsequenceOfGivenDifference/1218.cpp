#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        unordered_map<int, int> f;
        int ans = 0;
        for (int ai : arr) {
            f[ai] = f.count(ai - difference) == 0 ? 1 : f[ai - difference] + 1;
            ans = max(ans, f[ai]);
        }
        return ans;
    }
};