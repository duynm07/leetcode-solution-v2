#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListFromSequence(vector<int> sequence) {
    ListNode *list = nullptr;
    ListNode *head = nullptr;
    for (int val : sequence) {
        ListNode *node = new ListNode(val);
        if (list == nullptr) {
            head = node;
            list = node;
        } else {
            list->next = node;
            list = node;
        }
    }
    return head;
}

void printList(ListNode *list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

void insertVal(ListNode **root, int val) {
    ListNode *temp = new ListNode;
    ListNode *ptr;
    temp->val = val;
    temp->next = nullptr;

    if (*root == nullptr)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr)
            return head;
        bool checkLowerThanX = false;
        bool checkGreaterThanX = false;
        int listSize = 1;
        ListNode *last = head;
        while (last->next != nullptr) {
            listSize++;
            checkLowerThanX = checkLowerThanX || last->val < x || last->next->val < x;
            checkGreaterThanX = checkGreaterThanX || last->val >= x || last->next->val >= x;
            last = last->next;
        }

        if (!checkLowerThanX || !checkGreaterThanX)
            return head;

        ListNode *it = head;
        ListNode *prev = nullptr;
        ListNode *done = last;
        while (listSize--) {
            if (it->val >= x) {
                last->next = it;
                if (prev != nullptr)
                    prev->next = it->next;
                else {
                    head = it->next;
                }
                ListNode *temp = it->next;
                it->next = nullptr;
                last = it;
                it = temp;
            } else {
                prev = it;
                it = it->next;
            }
        }

        return head;
    }
};

int main() {
    Solution sol = Solution();
    // vector<int> nums = {1, 4, 3, 0, 5, 2};
    vector<int> nums = {2, 1};
    ListNode *head = createListFromSequence(nums);
    ListNode *ans = sol.partition(head, 2);

    printList(ans);
    // printList(ans);
}