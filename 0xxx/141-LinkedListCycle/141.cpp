#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insert(ListNode **root, int val) {
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

ListNode *createListFromSequence(std::vector<int> sequence) {
    ListNode *list = nullptr;
    for (int val : sequence) {
        insert(&list, val);
    }
    return list;
}

void printList(ListNode *list) {
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int len(ListNode *list) {
    int n = 0;
    while (list != nullptr) {
        n++;
        list = list->next;
    }
    return n;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        if (head->next == head)
            return true;
        ListNode *rab = head;
        ListNode *tut = head;
        while (tut != rab) {
            if (rab->next == nullptr || rab->next->next == nullptr || tut->next == nullptr)
                return false;
            rab = rab->next->next;
            tut = tut->next;
        }
        return tut == rab;
    }
};