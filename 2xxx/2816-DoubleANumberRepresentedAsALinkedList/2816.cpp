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
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = i >= 0 ? num1[i] - '0' : 0;
            int digit2 = j >= 0 ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;

            result += to_string(sum);

            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    ListNode *doubleIt(ListNode *head) {
        if (head->val == 0)
            return head;
        string number = "";
        while (head != nullptr) {
            number = number + to_string(head->val);
            head = head->next;
        }
        number = addStrings(number, number);
        ListNode *ans = nullptr;
        while (number.length()) {
            int digit = number.back() - '0';
            ListNode *temp = new ListNode(digit);
            temp->next = ans;
            ans = temp;
            number.pop_back();
        }
        return ans;
    }
};