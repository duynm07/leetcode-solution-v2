#include <algorithm>
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
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        if (head->next == nullptr)
            return head;
        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            int newVal = gcd(ptr->val, ptr->next->val);
            ListNode *newNode = new ListNode(newVal, ptr->next);
            ptr->next = newNode;
            ptr = newNode->next;
        }
        return head;
    }
};

int main() {
    vector<int> nums = {18, 6, 10, 3};
    ListNode *head = createListFromSequence(nums);

    Solution sol = Solution();
    ListNode *ans = sol.insertGreatestCommonDivisors(head);
    printList(ans);
}