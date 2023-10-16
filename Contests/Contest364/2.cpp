#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long sumHeight(vector<int> &maxHeights, int mntIndex) {
        long long sum = maxHeights[mntIndex];
        int temp = sum;
        for (int i = mntIndex - 1; i >= 0; i--) {
            int height = min(temp, maxHeights[i]);
            sum += (long long)height;
            temp = height;
        }
        temp = maxHeights[mntIndex];
        for (int i = mntIndex + 1; i < maxHeights.size(); i++) {
            int height = min(temp, maxHeights[i]);
            sum += (long long)height;
            temp = height;
        }
        return sum;
    }
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        long long ans;
        for (int i = 0; i < maxHeights.size(); i++) {
            cout << i << " " << sumHeight(maxHeights, i) << endl; 
            ans = max(ans, sumHeight(maxHeights, i));
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();

    vector<int> heights = {6, 5, 3, 9, 2, 7};
    cout << sol.maximumSumOfHeights(heights);

    return 0;
}