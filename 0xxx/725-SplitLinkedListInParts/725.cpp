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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> ans;
        int n = 0;
        ListNode *curr = head;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }

        int base = n / k;
        int extra = n % k;

        curr = head;
        for (int i = 0; i < k; i++) {
            ans.push_back(curr);
            if (curr == NULL)
                continue;
            ListNode *last;
            for (int j = 0; j < base + (extra > 0); j++) {
                last = curr;
                curr = curr->next;
            }
            last->next = NULL;
            extra--;
        }

        return ans;
    }
};