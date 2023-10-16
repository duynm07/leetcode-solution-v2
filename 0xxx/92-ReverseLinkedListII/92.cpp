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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right)
            return head;
        int count = 0;
        ListNode *ans = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *subHead;
        while (count < right) {
            count++;
            if (count < left)
                prev = head;
            else if (count == left) {
                if (prev != NULL)
                    prev->next = NULL;
                subHead = head;
            }
            if (count == right) {
                next = head->next;
                head->next = NULL;
            }
            head = head->next;
        }

        ListNode *subTail = subHead;
        subHead = reverse(subHead);

        subTail->next = next;
        if (prev != NULL) {
            prev->next = subHead;
            return ans;
        } else {
            return subHead;
        }
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head = createListFromSequence(a);

    Solution sol = Solution();
    ListNode *ans = sol.reverseBetween(head, 6, 9);
    printList(ans);
}