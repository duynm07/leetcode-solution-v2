#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        queue<int> line;
        for (int i = 0; i < tickets.size(); i++)
            line.push(i);

        int ans = 0;
        while (tickets[k] > 0) {
            ans++;
            int i = line.front();
            line.pop();
            tickets[i]--;
            if (tickets[i] > 0)
                line.push(i);
        }

        return ans;
    }
};