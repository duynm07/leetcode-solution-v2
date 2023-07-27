#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int> &nums) {
        int n = nums.size();
        int first = 1;
        int last = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                first = i;
            if (nums[i] == n)
                last = i;
        }

        return first > last ? first + n - (last + 2) : first + n - (last + 1);
    }
};