#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void increaseString(string &s) {
        int idx = s.length() - 1;
        while (s[idx] == '1')
            s[idx--] = '0';
        s[idx] = '1';
    }

    string findDifferentBinaryString(vector<string> &nums) {
        sort(nums.begin(), nums.end());
        string currentString(nums.size(), '0');

        for (int i = 0; i < nums.size() && currentString == nums[i]; i++)
            increaseString(currentString);

        return currentString;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}