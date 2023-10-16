#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == NULL)
            return NULL;
        unordered_map<Node *, Node *> nodeMap;

        Node *currOrg = head;
        Node *currNew = new Node(head->val);
        Node *ans = currNew;

        while (currOrg != NULL) {
            nodeMap[currOrg] = currNew;
            currOrg = currOrg->next;
            if (currOrg == NULL) {
                currNew->next = NULL;
            } else {
                Node *node = new Node(currOrg->val);
                currNew->next = node;
            }
            currNew = currNew->next;
        }

        currOrg = head;
        currNew = ans;

        while (currOrg != NULL) {
            currNew->random = nodeMap[currOrg->random];
            currOrg = currOrg->next;
            currNew = currNew->next;
        }

        return ans;
    }
};