/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return NULL; // size = 0
        if (head->next == NULL)
            return head; // size = 1

        ListNode *prevNode = NULL;
        ListNode *nextNode = head->next;

        while (head != NULL)
        {
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
            if (nextNode != NULL)
                nextNode = nextNode->next;
        }

        head = prevNode;

        return head;
    }
};
