#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int, int> counter;
        unordered_map<int, vector<int>> adjs;
        for (vector<int> pair : adjacentPairs) {
            adjs[pair[0]].push_back(pair[1]);
            adjs[pair[1]].push_back(pair[0]);
        }

        int number;
        for (vector<int> pair : adjacentPairs) {
            if (adjs[pair[0]].size() == 1) {
                number = pair[0];
                break;
            } else if (adjs[pair[1]].size() == 1) {
                number = pair[1];
                break;
            }
        }

        vector<int> ans;
        ans.push_back(number);

        for (int i = 0; i < adjacentPairs.size(); i++) {
            int nextNumber = adjs[number].size() > 1 && adjs[number][0] == number ? adjs[number][1] : adjs[number][0];
            for (int j = 0; j < adjs[nextNumber].size(); j++) {
                if (adjs[nextNumber][j] == number)
                    adjs[nextNumber][j] = nextNumber;
            }

            number = nextNumber;
            ans.push_back(number);
        }

        return ans;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}