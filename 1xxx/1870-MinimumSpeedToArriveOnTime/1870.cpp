#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> &dist, int speed, double hour) {
        double totalHour = 0;
        for (int i = 0; i < dist.size() - 1; i++)
            totalHour += ceil((double)dist[i] / (double)speed);
        return totalHour + (double)dist[dist.size() - 1] / (double)speed <= hour;
    }
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int first = 1;
        int last = 1e8;
        int ans = -1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (check(dist, mid, hour)) {
                if (ans < 0 || mid < ans)
                    ans = mid;
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> dist = {1, 3, 2};
    cout << sol.minSpeedOnTime(dist, 2.1);
}