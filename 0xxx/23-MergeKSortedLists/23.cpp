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

/**
 * @brief The main solution class which is submited.
 *
 */
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

    ListNode *mergeLists(vector<ListNode *> &lists, int first, int last) {
        if (first == last) {
            return lists[first];
        } else if (first + 1 == last) {
            return mergeTwoLists(lists[first], lists[first + 1]);
        } else {
            int mid = (first + last + 1) / 2;
            return mergeTwoLists(mergeLists(lists, first, mid - 1), mergeLists(lists, mid, last));
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeLists(lists, 0, lists.size() - 1);
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> sequence1 = {1, 4, 5};
    std::vector<int> sequence2 = {1, 3, 4};
    std::vector<int> sequence3 = {2, 6};
    ListNode *list1 = createListFromSequence(sequence1);
    ListNode *list2 = createListFromSequence(sequence2);
    ListNode *list3 = createListFromSequence(sequence3);

    Solution solution = Solution();
    vector<ListNode *> list = {list1, list2, list3};
    ListNode *result = solution.mergeKLists(list);

    printList(result);

    return 0;
}