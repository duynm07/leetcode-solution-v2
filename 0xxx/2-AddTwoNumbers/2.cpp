#include <iostream>
#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListFromSequence(std::vector<int> sequence) {
    ListNode *list = nullptr;
    for (int val : sequence) {
        insert(&list, val);
    }
    return list;
}

void printList(ListNode *list) {
    while (list != nullptr) {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

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

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int t = 0;
        ListNode *ans = nullptr;

        while (l1 != nullptr || l2 != nullptr) {
            int d1 = l1 == nullptr ? 0 : l1->val;
            int d2 = l2 == nullptr ? 0 : l2->val;

            insert(&ans, (d1 + d2 + t) % 10);
            t = d1 + d2 + t < 10 ? 0 : 1;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (t == 1)
            insert(&ans, 1);

        return ans;
    }
};

int main() {
    std::vector<int> num1 = {2, 4, 3, 2, 4, 1};
    std::vector<int> num2 = {5, 6, 4};

    ListNode *list1 = createListFromSequence(num1);
    ListNode *list2 = createListFromSequence(num2);

    Solution solution = Solution();
    ListNode *sum = solution.addTwoNumbers(list1, list2);
    printList(sum);

    return 0;
}