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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        // If one of two list is empty, return the other list immediately
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // A buffer that walk through both lists
        ListNode *head = nullptr;

        // Start at the list which has the lower first value
        if (list1->val < list2->val) {
            head = list1;
            // Always pick the lower value to be the next point.
            while (list2 != nullptr) {
                if (head->next == nullptr || list2->val < head->next->val) {
                    ListNode *headNext = head->next;
                    head->next = list2;
                    list2 = headNext;
                }
                head = head->next;
            }
            return list1;
        } else {
            head = list2;
            // Same thing as above
            while (list1 != nullptr) {
                if (head->next == nullptr || list1->val < head->next->val) {
                    ListNode *headNext = head->next;
                    head->next = list1;
                    list1 = headNext;
                }
                head = head->next;
            }
            return list2;
        }
    }

    ListNode *sortList(ListNode *head) {
        int n = len(head);
        if (n == 1)
            return head;

        int mid = n / 2 - 1;
        ListNode *list1 = head;
        while (mid--) {
            list1 = list1->next;
        }
        ListNode *list2 = list1->next;
        list1->next = nullptr;

        // printList(head);
        // printList(list2);

        return mergeTwoLists(sortList(head), sortList(list2));
    }
};

int main() {
    Solution sol = Solution();

    // vector<int> nums = {3,6,6,3,2,6,7,7,4,2,4,6};
    vector<int> nums = {6, 3, 2};
    ListNode *head = createListFromSequence(nums);
    head = sol.sortList(head);
    printList(head);
    return 0;
}