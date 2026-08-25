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

class Solution
{
public:
    ListNode *reverse_list(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = cur->next;

        while (cur)
        {
            cur->next = prev;

            prev = cur;
            cur = next;
            if (cur)
                next = cur->next;
        }

        return prev;
    }

    int get_size(ListNode *head)
    {
        int size = 0;
        ListNode *temp = head;

        while (temp)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }

    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next) // size = 0, 1, 2
            return;

        int size = get_size(head);
        int i = 1;
        ListNode *temp1 = head;

        while (i < size / 2)
        {
            temp1 = temp1->next;
            i++;
        }

        ListNode *temp2 = temp1->next; // temp2 = head of 2nd list
        temp1->next = nullptr;

        temp1 = head;                // head of 1st list
        temp2 = reverse_list(temp2); // head of reversed 2nd list
        ListNode *next1;
        ListNode *next2;

        while (temp1 && temp2)
        {
            next1 = temp1->next;
            next2 = temp2->next;

            temp1->next = temp2;
            if (next1)
                temp2->next = next1;

            temp1 = next1;
            temp2 = next2;
        }
    }
};
