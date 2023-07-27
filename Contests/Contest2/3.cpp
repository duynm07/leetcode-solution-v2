#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int> &nums) {
        int left = 0;
        long long ans = 0;
        int n = nums.size();
        multiset<int> mySet;

        for (int right = 0; right < n; right++) {
            minHeap.push(nums[right]);
            maxHeap.push(nums[right]);
            while (maxHeap.top() - minHeap.top() > 2) {
                maxHeap.pop();
                minHeap.po
            }
        }
    }
};