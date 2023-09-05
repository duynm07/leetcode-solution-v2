#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        vector<int> ans;
        queue<int> q;
        sort(deck.begin(), deck.end());
        for (int i = deck.size() - 1; i >= 0; i--) {
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
            q.push(deck[i]);
        }
        for (int i = deck.size() - 1; i >= 0; i--) {
            deck[i] = q.front();
            q.pop();
        }
        return deck;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = sol.deckRevealedIncreasing(deck);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}