#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> ans;
        for (vector<int> query : queries) {
            int x = query[0];
            int y = query[1];
            int r = query[2];

            int count = 0;
            for (vector<int> point : points) {
                int xi = point[0];
                int yi = point[1];
                int sqrDistance = (xi - x) * (xi - x) + (yi - y) * (yi - y);
                if (sqrDistance <= r)
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};