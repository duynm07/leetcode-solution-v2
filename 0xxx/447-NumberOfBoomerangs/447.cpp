#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;

        for (vector<int> point : points) {
            unordered_map<int, int> countDistance;
            for (vector<int> otherPoint : points) {
                int squareDistance = (otherPoint[1] - point[1]) * (otherPoint[1] - point[1]) + (otherPoint[0] - point[0]) * (otherPoint[0] - point[0]);
                if (countDistance.count(squareDistance) == 0) {
                    countDistance[squareDistance] = 1;
                } else {
                    countDistance[squareDistance]++;
                }
            }
            for (const auto pair : countDistance) {
                ans += pair.second * (pair.second - 1);
            }
        }

        return ans;
    }
};