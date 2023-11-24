#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int totalLength = 0;
        for (int i = 0; i < garbage.size(); i++) {
            totalLength += garbage[i].length();
        }

        int totalTime = 0;
        for (int i = 0; i < travel.size(); i++)
            totalTime += travel[i];

        int timeM = totalTime, timeP = totalTime, timeG = totalTime;
        bool foundM = false, foundP = false, foundG = false;
        for (int i = garbage.size() - 1; i > 0; i--) {
            if (garbage[i].find('M') == string::npos && !foundM) {
                timeM -= travel[i - 1];
            } else {
                foundM = true;
            }
            if (garbage[i].find('P') == string::npos && !foundP) {
                timeP -= travel[i - 1];
            } else {
                foundP = true;
            }
            if (garbage[i].find('G') == string::npos && !foundG) {
                timeG -= travel[i - 1];
            } else {
                foundG = true;
            }
        }

        return timeM + timeP + timeG + totalLength;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}