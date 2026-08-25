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
    int get_size(ListNode *head)
    {
        int size = 0;

        ListNode *temp = head;

        while (temp)
        {
            temp = temp->next;
            size++;
        }

        return size;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = get_size(head);
        int targetIndx = size - n;

        if (targetIndx == 0)
        {
            head = head->next;
        }
        else if (targetIndx == size - 1)
        {
            ListNode *temp = head;
            ListNode *prev = nullptr;

            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;
        }
        else
        {
            ListNode *prev = nullptr;
            ListNode *cur = head;
            ListNode *next = cur->next;
            int i = 0;

            while (i != targetIndx)
            {
                prev = cur;
                cur = next;
                next = cur->next;
                i++;
            }

            prev->next = next;
        }

        return head;
    }
};
