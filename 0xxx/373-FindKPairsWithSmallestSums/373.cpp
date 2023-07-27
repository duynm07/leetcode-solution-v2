#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int i1 = 0;
        int i2 = 0;
        vector<vector<int>> ans;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i = 0; i < min(k, n1 * n2); i++) {
            ans.push_back({nums1[i1], nums2[i2]});
            if (i1 == n1 - 1) {
                i2++;
            } else if (i2 == n2 - 1) {
                i1++;
            } else {
                if (nums1[i1 + 1] + nums2[i2] < nums1[i1] + nums2[i2 + 1]) {
                    i1++;
                } else {
                    i2++;
                }
            }
        }

        return ans;
    }
};