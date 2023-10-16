#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class MyHashMap {
private:
    vector<pair<int, int>> data;

public:
    MyHashMap() {
    }

    void put(int key, int value) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].first == key) {
                data[i].second = value;
                return;
            }
        }
        data.push_back({key, value});
    }

    int get(int key) {
        for (pair<int, int> item : data) {
            if (item.first == key) {
                return item.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].first == key) {
                data.erase(data.begin() + i);
                return;
            }
        }
    }
};

int main() {

    return 0;
}