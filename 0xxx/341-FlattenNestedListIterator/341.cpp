#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    vector<int> flattened;
    int index;

    void dfs(NestedInteger u) {
        if (u.isInteger()) {
            flattened.push_back(u.getInteger());
            return;
        }
        vector<NestedInteger> children = u.getList();
        for (NestedInteger v : children)
            dfs(v);
    }

public:
    vector<NestedInteger> nestedList;

    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        for (NestedInteger u : nestedList) {
            dfs(u);
        }
    }

    int next() {
        return flattened[index++];
    }

    bool hasNext() {
        return index >= flattened.size();
    }
};

int main() {

    return 0;
}