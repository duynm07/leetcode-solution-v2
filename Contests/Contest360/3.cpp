#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> convert2array(int n) {
        vector<int> ans;
        int p = 0;
        while (n) {
            int bit = n % 2;
            if (bit)
                ans.push_back(p);
            p++;
            n /= 2;
        }
        return ans;
    }
    bool check(vector<int> &nums, vector<int> &arr) {
        sort(nums.begin(), nums.end());
        int j = 0;
        int i = 0;
        while (j < arr.size() && i < nums.size()) {
            if (nums[i] == arr[j]) {
                i++;
                j++;
                continue;
            }
            
        }
    }
    int minOperations(vector<int> &nums, int target) {
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = sol.convert2array(8);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}