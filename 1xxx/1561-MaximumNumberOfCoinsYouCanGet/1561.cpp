#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &piles) {
        sort(piles.begin(), piles.end());

        for (int i = piles.size() / 3 + 2; i < piles.size(); i += 2)
            piles[i] += piles[i - 2];

        return piles[piles.size() - 2];
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}